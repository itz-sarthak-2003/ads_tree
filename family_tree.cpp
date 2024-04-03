#include <iostream>
#define max 32
using namespace std;
class FMT
{
public:
    int age, bdate;
    string name, gender;
    FMT *lchild, *rchild;
    void accept();
    void insert(FMT *root, FMT *next);
    void display_preorder(FMT *root);
    void display_not(FMT *root);
    void display_postorder(FMT *root);
    void mirror(FMT *root);
    void calculate();
    void find_member(FMT *root, string x);
    void leaf(FMT *root);
    void height();
} *root, *st[max];
int c = 0, c1 = 0;

void FMT::height()
{
    if(c>=c1){
    cout << "the height of tree is : " << c;
}else{
    cout<<"the height is : "<<c1;
}
}
void FMT::leaf(FMT *root)
{
    if (root == NULL)
        return;

    if (root->lchild == NULL && root->rchild == NULL)
        cout << "\n"
             << root->name << "\t" << root->age << "\t" << root->gender << "\t" << root->bdate << endl;

    leaf(root->lchild);
    leaf(root->rchild);
}

void FMT::calculate()
{
    cout << "total no. of records : " << c;
}

void FMT::find_member(FMT *root, string x)
{
    if (root == NULL)
    {
        cout << "family tree is empty";
    }
    if (root->name == x)
    {
        cout << "family member is found : " << root->name << endl;
        return;
    }
    find_member(root->lchild, x);
    find_member(root->rchild, x);
}

void FMT::mirror(FMT *root)
{
    FMT *temp;
    if (root == NULL)
    {
        return;
    }
    else
    {
        mirror(root->lchild);
        mirror(root->rchild);
        temp = (root->lchild);
        root->lchild = root->rchild;
        root->rchild = temp;
    }
}
void FMT::display_preorder(FMT *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        cout << "\n"
             << root->name << "\t" << root->age << "\t" << root->gender << "\t" << root->bdate << endl;
        display_preorder(root->lchild);
        display_preorder(root->rchild);
    }
}
void FMT::display_not(FMT *root)
{
    if (root == NULL)
        return;

    int top = -1;
    FMT *temp = root;

    while (temp != NULL || top != -1)
    {
        while (temp != NULL)
        {
            top++;
            st[top] = temp;
            temp = temp->lchild;
        }
        
        if (top != -1)
        {
            temp = st[top];
            cout << "\n" << temp->name << "\t" << temp->age << "\t" << temp->gender << "\t" << temp->bdate << endl;
            temp = temp->rchild;
            top--;
        }
    }
}
void FMT::display_postorder(FMT *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        display_postorder(root->lchild);
        display_postorder(root->rchild);
        cout << "\n"
             << root->name << "\t" << root->age << "\t" << root->gender << "\t" << root->bdate << endl;
    }
}

void FMT::accept()
{
    int ch;
    FMT *next;
    root = new FMT();
    cout << "enter the following family information :" << endl;
    cout << "name , age , gender , bdate" << endl;
    cin >> root->name >> root->age >> root->gender >> root->bdate;
    c = 1;
    root->lchild = NULL;
    root->rchild = NULL;
    do
    {
        cout << "u want to add more family members if yes then press 1 otherwise press any key : " << endl;
        cin >> ch;
        if (ch == 1)
        {
            next = new FMT();
            cout << "enter the following family information :" << endl;
            cout << "name , age , gender , bdate" << endl;
            cin >> next->name >> next->age >> next->gender >> next->bdate;
            if (c > c1)
                c1 = c;
            c = 1;
            next->lchild = NULL;
            next->rchild = NULL;
            insert(root, next);
        }
    } while (ch == 1);
}
void FMT::insert(FMT *root, FMT *next)
{
    string chr;
    cout << "where u want to inserted data either left or right of "
         << "'" << root->name << "'"
         << " L or R : " << endl;
    cin >> chr;
    c++;
    if (chr == "l" || chr == "L")
    {
        if (root->lchild == NULL)
        {
            root->lchild = next;
        }
        else
        {
            insert(root->lchild, next);
        }
    }
    if (chr == "r" || chr == "R")
    {
        if (root->rchild == NULL)
        {
            c++;
            root->rchild = next;
        }
        else
        {
            insert(root->rchild, next);
        }
    }
}
int main()
{
    FMT n;
    int ch;
    string x;
    do
    {
        cout << "\nWELCOME TO FAMILY TREE ! ";
        cout << "\n1.Accept the family members \n2.Display family members in PREORDER \n3.Display family members in not recursvie \n4.Display family members in POSTORDER \n5.Display mirror image of ur family tree \n6.calculate how many members in the family \n7.find family member \n8.leaf \n9.height \n10.exit";
        cout << "\nENTER YOUR CHOICE = : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            n.accept();
            break;
        case 2:
            cout << "\nName\tAge\tGender\tDOB" << endl;
            n.display_preorder(root);
            break;
        case 3:
            cout << "\nName\tAge\tGender\tDOB" << endl;
            n.display_not(root);
            break;
        case 4:
            cout << "\nName\tAge\tGender\tDOB" << endl;
            n.display_postorder(root);
            break;
        case 5:
            cout << "for displaying mirror image of family tree u can choice preorder,inorder,postorder any of them " << endl;
            n.mirror(root);
            break;
        case 6:
            n.calculate();
            break;
        case 7:
            cout << "enter the name of the family member u want to search for : ";
            cin >> x;
            n.find_member(root, x);
            break;
        case 8:
            n.leaf(root);
            break;
        case 9:
           n.height();
            break;
        case 10:
           
              exit(0);
            cout << "Thanks........";
            break;
        default:
            cout << "Wrong choice";
        }
    } while (ch != 10);
    return 1;
}
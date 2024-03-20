#include <iostream>
using namespace std;
class FMT
{
public:
    int age, bdate,c=0;
    string name, gender;
    FMT *lchild, *rchild;
    void accept();
    void insert(FMT *root, FMT *next);
    void display_preorder(FMT *root);
    void display_inorder(FMT *root);
    void display_postorder(FMT *root);
    void mirror(FMT *root);
    void calculate();
    // void find_member(FMT *root,string x);
} *root;

void FMT::calculate(){
    cout<<"total no. of records : "<<c;
}

// void FMT::find_member(FMT *root,string x){
//             cout<<"enter name of family member u want to search : "<<endl;
//         cin>>x;
//     if(root==NULL){
//         return;
//     }
//     if(root->name==x){
//         cout<<"family member is found : "<<root->name;
//         return(find_member(root->rchild,x));
//         return(find_member(root->lchild,x));
//     }
//     else{
//         cout<<"family member is not found "<<endl;
//     }
// }

void FMT::mirror(FMT *root){
    FMT *temp;
    if(root==NULL){
        return;}
        else{
        mirror(root->lchild);
        mirror(root->rchild);
        temp=(root->lchild);
        root->lchild=root->rchild;
        root->rchild=temp;
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
        cout << "\n"<< root->name << "\t" << root->age << "\t" << root->gender << "\t" << root->bdate << endl;
        display_preorder(root->lchild);
        display_preorder(root->rchild);
    }
}
void FMT::display_inorder(FMT *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        display_inorder(root->lchild);
        cout << "\n"<< root->name << "\t" << root->age << "\t" << root->gender << "\t" << root->bdate << endl;
        display_inorder(root->rchild);
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
        cout << "\n"<< root->name << "\t" << root->age << "\t" << root->gender << "\t" << root->bdate << endl;
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
    root->lchild = NULL;
    root->rchild = NULL;
    c++;
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
            next->lchild = NULL;
            next->rchild = NULL;
            insert(root, next);
        }
    } while (ch == 1);
}
void FMT::insert(FMT *root, FMT *next)
{
    string chr;
    cout << "where u want to inserted data either left or right of " <<"'"<< root->name <<"'" << " L or R : " << endl;
    cin >> chr;
    if (chr == "l" || chr == "L")
    {
        if (root->lchild == NULL)
        {c++;
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
        {c++;
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
    // fmt.accept();
    // fmt.display(root);

    int ch;
    string x;
    do
    {
        cout << "\nWELCOME TO FAMILY TREE ! ";
        cout << "\n1.Accept the family members \n2.Display family members in PREORDER \n3.Display family members in INORDER \n4.Display family members in POSTORDER \n5.Display mirror image of ur family tree \n6.calculate how many members in the family \n7.exit";
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
            n.display_inorder(root);
            break;
        case 4:
            cout << "\nName\tAge\tGender\tDOB" << endl;
            n.display_postorder(root);
            break;
        case 5:
            cout<<"for displaying mirror image of family tree u can choice preorder,inorder,postorder any of them "<<endl;
            n.mirror(root);
            //n.display_inorder(root);
            break;
            case 6:
            n.calculate();
            break;
        case 7:
             exit(0);
            cout << "Thanks........";
            break;
        default:
            cout << "Wrong choice";
        }
    } while (ch != 7);
    return 1;
}
#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *left,*right;
    node(int value){
        data=value;
        left=right=NULL;
    }
};
node *BT(){
    int x;
    cin>>x;
    if(x==-1)
    return NULL;
    node *temp=new node(x);
    cout<<"enter left child of "<<x<<":"<<endl;
    temp->left=BT();
    cout<<"enter the right child of "<<x<<":"<<endl;
    temp->right=BT();
    return temp;
}
void preorder(node *root){
    if(root==NULL)
    return;
    cout<<root->data;
    preorder(root->left);
    preorder(root->right);  
}
void inorder(node * root){
    if(root==NULL)
    return;
    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
}
void postorder(node *root){
    if(root==NULL)
    return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data;
}
int main()
{
    cout<<"enter root node "<<endl;
    node *root;
    root=BT();
    cout<<"preorder : ";
    preorder(root);
    cout<<"\n inorder : ";
    inorder(root);
    cout<<"\n postorder : ";
    postorder(root);
return 0;
}
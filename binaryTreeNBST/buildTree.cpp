#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node* left, *right;

    node(int key)
    {
        data=key;
        left=NULL;
        right=NULL;
    }
};
node* buildTree(void);
void printPre(node* root)
{
    if(!root)
    {
        return;
    }
    cout<<root->data<<" ";

    printPre(root->left);
    printPre(root->right);
}
void printIn(node* root)
{
    if(!root)
    {
        return;
    }

    printIn(root->left);
    cout<<root->data<<" ";
    printIn(root->right);
}
void printPos(node* root)
{
    if(!root)
    {
        return;
    }

    printPos(root->left);
    printPos(root->right);
    cout<<root->data<<" ";
}
node* buildTreeInInorderFashion(void);
int main()
{
    node* root;
    root=buildTreeInInorderFashion();//buildTree();
    cout<<endl;
    //printPre(root);
    cout<<endl;
    printIn(root);
    cout<<endl;
    //printPos(root);
    return 0;
}
node* buildTreeInInorderFashion(void)
{
    node* left;
    int d1;
    cin>>d1;
    if(d1==-1)
    {
        left=NULL;
    }
    if(d1==-2)
    {
        return NULL;
    }
    int d2;
    cin>>d2;
    node* root=new node(d2);

    //root=
    root->left=left;
    root->right=buildTree();
    return root;
}
node* buildTree(void)
{
    int d;
    cin>>d;
    if(d==-1)
    {
        return NULL;
    }
    node* root=new node(d);

    root->left=buildTree();
    root->right=buildTree();
    return root;
}

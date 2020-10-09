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
int countAllNodes(node* root)
{
    if(!root)
    {
        return 0;
    }

    return 1+countAllNodes(root->left)+countAllNodes(root->right);
}
int sumAllNodes(node *root)
{
    if(!root)
    {
        return 0;
    }
    return root->data+sumAllNodes(root->left)+sumAllNodes(root->right);
}
int main()
{
    node* root;
    root=buildTree();
    //cout<<countAllNodes(root);
    cout<<sumAllNodes(root);
    return 0;
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

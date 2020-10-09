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
int diameterOfTree(node* root);
int main()
{
    node* root;
    root=buildTree();
    cout<<diameterOfTree(root);
    return 0;
}
int height(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return 1+max(height(root->left), height(root->right));
}
int diameterOfTree(node* root)
{
    if(!root)
    {
        return 0;
    }
    return max(height(root->left)+height(root->right),
                max(diameterOfTree(root->left), diameterOfTree(root->right)) );
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


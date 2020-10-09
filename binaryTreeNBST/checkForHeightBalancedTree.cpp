
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
class Pair
{
public:
    int height;
    bool Bal;
};
node* buildTree(void);
Pair checkForBalancedHeightTree(node* root);
int main()
{
    node* root;
    root=buildTree();
    Pair p=checkForBalancedHeightTree(root);
    if(p.Bal)
        cout<<"Yes, Balanced Tree";
    else
        cout<<"Not Balanced Tree!";
    return 0;
}
Pair checkForBalancedHeightTree(node* root)
{
    Pair p;
    if(!root)
    {
        p.height=0;
        p.Bal=true ;
        return p;
    }
    Pair left=checkForBalancedHeightTree(root->left);
    Pair right=checkForBalancedHeightTree(root->right);

    int d=left.height-right.height;
    p.Bal=(d==0||d==-1||d==1);
    p.height=max(left.height, right.height)+1;

    return p;
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

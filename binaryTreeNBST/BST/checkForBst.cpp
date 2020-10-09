
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

bool checkForBst(node* root, int mn=INT_MIN, int mx=INT_MAX);
int main()
{
    node* root;
    root=buildTree();
    if(checkForBst(root))
        cout<<"Yes, tree is bst";
    else
        cout<<"Not a bst!";
    return 0;
}
bool checkForBst(node* root, int mn, int mx)
{
    if(!root)
    {
        return true;
    }
    return (root->data>=mn&&root->data<=mx&&checkForBst(root->left, mn, root->data)&&checkForBst(root->right, root->data, mx));
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



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
node* buildBst(void);
bool searchDataBst(node* root, int d);

int main()
{
    node* root;
    root=buildBst();
    if(searchDataBst(root, 5))
        cout<<"Yes, found";
    else
        cout<<"Not found";
    return 0;
}
bool searchDataBst(node* root, int d)
{
    if(!root)
    {
        return false;
    }
    else if(d==root->data)
    {
        return true;
    }
    else
    {
        if(d<=root->data)
            return searchDataBst(root->left, d);
        else
            return searchDataBst(root->right, d);
    }
}
node* insertBst(node* root, int d)
{
    if(!root)
    {
        return new node(d);
    }
    if(d<root->data)
    {
        root->left=insertBst(root->left, d);
    }
    else
    {
        root->right=insertBst(root->right, d);
    }
    return root;
}
node* buildBst(void)
{
    node* root=NULL;
    int d;
    cin>>d;
    while(d!=-1)
    {
        root = insertBst(root, d);
        cin>>d;
    }
    return root;
}

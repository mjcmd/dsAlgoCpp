
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
bool identicalTrees(node* r1, node* r2);

int main()
{
    node *r1, *r2;
    r1=buildTree();
    r2=buildTree();
    if(identicalTrees(r1, r2))
        cout<<"Yes, identical Trees";
    else
        cout<<"Not identical trees!";
    return 0;
}
bool identicalTrees(node* r1, node* r2)
{
    if(!r1&&!r2)
    {
        return true;
    }
    if(!r1)
    {
        return false;
    }
    if(!r2)
    {
        return false;
    }
    if(identicalTrees(r1->left, r2->left)&&identicalTrees(r1->right, r2->right))
        return true;
    else
        return false;

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

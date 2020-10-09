
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
    int diameter;
};
node* buildTree(void);
Pair diameterOptimised(node* root);
int main()
{
    node* root;
    root=buildTree();
    Pair p=diameterOptimised(root);
    cout<<p.diameter;
    return 0;
}
Pair diameterOptimised(node* root)
{
     Pair p;
    if(!root)
    {
        p.height=p.diameter=0;
        return p;
    }
    Pair left=diameterOptimised(root->left);
    Pair right=diameterOptimised(root->right);

    p.height=max(left.height, right.height)+1;
    p.diameter=max(left.height+right.height, max(left.diameter, right.diameter));

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

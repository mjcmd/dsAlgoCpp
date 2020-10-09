
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
node* ptrToANodePre(node* root, int d);
node* ptrToANodeIn(node* root, int d);
node* ptrToANodePos(node* root, int d);
int main()
{
    node* root;
    root=buildTree();
    int d;
    cin>>d;
    //node* tmp=ptrToANode(root, d);
    //node* tmp=ptrToANodeIn(root, d);
    node* tmp=ptrToANodePos(root, d);

    if(tmp!=NULL)
        cout<<tmp->data;
    else
        cout<<"not present!";
    return 0;
}
node* ptrToANodePre(node* root, int d){
    if(root==NULL)
        return root;
    if(root->data==d)
        return root;
    node* left=ptrToANodePre(root->left, d);
    node* right=ptrToANodePre(root->right, d);
    if(left)
        return left;
    else if(right)
        return right;
    else
        return NULL;
}
node* ptrToANodeIn(node* root, int d){
    if(root==NULL)
        return root;

    node* left=ptrToANodeIn(root->left, d);
    if(root->data==d)
        return root;
    node* right=ptrToANodeIn(root->right, d);
    if(left)
        return left;
    else if(right)
        return right;
    else
        return NULL;
}
node* ptrToANodePos(node* root, int d){
    if(root==NULL)
        return root;

    node* left=ptrToANodePos(root->left, d);
    node* right=ptrToANodePos(root->right, d);

    if(root->data==d)
        return root;
    if(left)
        return left;
    else if(right)
        return right;
    else
        return NULL;
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

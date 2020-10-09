
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
void inOrder(node* root)
{
    if(!root)
    {
        return;
    }
    cout<<root->data;
    inOrder(root->left);

    inOrder(root->right);
    return;
}
void levelOrderPrintWithQueue(node* root);
int main()
{
    node* root;
    root=buildBst();
    levelOrderPrintWithQueue(root);
    //inOrder(root);
    return 0;
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
void levelOrderPrintWithQueue(node* root)
{
    queue<node*>   q;

    q.push(root);

    while(!q.empty())
    {
        node* f=q.front();
        cout<<f->data<<" ";

        q.pop();
        if(f->left)
            q.push(f->left);
        if(f->right)
            q.push(f->right);
    }
    return;
}

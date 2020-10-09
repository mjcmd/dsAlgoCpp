
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
void levelOrderPrintWithQueue(node* root);
node* buildBst(void);
node* deleteABstNode(node* root, int d);

int main()
{
    node* root;
    root=buildBst();
    root=deleteABstNode(root, 5);
    levelOrderPrintWithQueue(root);
    return 0;
}
node* deleteABstNode(node* r, int d)
{
    if(r->data==d)
    {
        if(!r->left&&!r->right)
        {
            return NULL;
        }
        else if(!r->left)
        {
            node* t=r->right;
            delete r;
            return t;
        }
        else if(!r->right)
        {
            node* t=r->left;
            delete r;
            return t;
        }
        else
        {
            node* t= r->right;
            t->left = r->left;
            delete r;
            return t;
        }
    }
    else
        {
            if(d<=r->data)
            {
                r->left=deleteABstNode(r->left, d);
            }
            else
            {
                r->right=deleteABstNode(r->right, d);
            }
            return r;
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

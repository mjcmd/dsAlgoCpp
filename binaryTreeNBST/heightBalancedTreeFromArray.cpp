
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
void levelOrderPrintWithQueue(node* root);
node* heightBalancedTreeFromArray(int *ar, int s, int e);
int main()
{
    node* root;
    //root=buildTree();
    int ar[]={1, 2, 3, 4};
    int n=sizeof(ar)/sizeof(ar[0]);
    root = heightBalancedTreeFromArray(ar, 0, n-1);
    levelOrderPrintWithQueue(root);
    return 0;
}
node* heightBalancedTreeFromArray(int *ar, int s, int e)
{
    if(s>e)
    {
        return NULL;
    }
    if(s==e)
    {
        node* tmp = new node(ar[s]);
        return tmp;
    }
    int mid=(s+e)/2;

    node* root=new node(ar[mid]);
    root->left=heightBalancedTreeFromArray(ar, s, mid-1);
    root->right=heightBalancedTreeFromArray(ar, mid+1, e);

    return root;

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

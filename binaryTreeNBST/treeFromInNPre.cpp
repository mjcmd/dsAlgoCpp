
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
//int index=-1;
node* buildTree(void);
node* treeFromInNPre(vector<int> in, int index, vector<int> pre, int s, int e);
void preOrder(node* root)
{
    if(!root)
    {
        return ;
    }
    cout<<root->data<<" ";
    preOrder( root->left);
    preOrder( root->right);
}
int main()
{
    node* root;
    vector<int> pre={1, 2, 3, 4, 8, 5, 6, 7};
    vector<int> in={3, 2, 8, 4, 1, 6, 7, 5};
    //root=buildTree();
    root=treeFromInNPre(in, 0, pre, 0, pre.size()-1);
    preOrder(root);
    return 0;
}
node* treeFromInNPre(vector<int> in, int index, vector<int> pre, int s, int e)
{

    if(s>e)
    {
        return NULL;
    }
    int i=s;
    for(; i<= e; i++)
    {
        if(in[index]=pre[i])
        {
            break;
        }
    }
    node* tmp=new node(in[i]);
    tmp->left=treeFromInNPre(in, index+1, pre, s, i-1);
    tmp->right=treeFromInNPre(in, index+1, pre, i+1, e);
    return tmp;
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

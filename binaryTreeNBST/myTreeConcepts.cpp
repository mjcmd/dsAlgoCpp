
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
void printBinaryTree(node* root);
int fun(node* root, int k1);
pair<bool, int> distOfaNodeFromRoot(node* root, int d);

int main()
{
    node* root;
    root=buildTree();

    //int cnt=fun(root, 0);
    //cout<<cnt;
    pair<bool, int> p=distOfaNodeFromRoot(root, 6);
    cout<<p.second;
    //cout<<cnt[0]<<" "<<cnt[1]<<" "<<cnt[2]<<endl;
    return 0;
}
pair<bool, int> distOfaNodeFromRoot(node* root, int d)
{
    static pair<bool, int> p={0, 0};
    if(!root)
    {
        p.first=false;
        return p;
    }
    //processing in preOrder fashion
    if(root->data==d)
    {
        p.first=true;
        p.second=p.second+1;
        return p;
    }
    //p.second=p.second+1;

    pair<bool, int>left, right;
    left=distOfaNodeFromRoot(root->left, d);
    right=distOfaNodeFromRoot(root->right, d);

    if(left.first)
    {
        p.second=left.second+1;
        return p;
    }
    if(right.first)
    {
        p.second=right.second+1;
        return p;
    }
    return p;

}
int fun(node* r, int k)
{
    //base condition for null node
    if(r==NULL)
        return k;

    k++;
    k=fun(r->left, k);
    k++;
    k=fun(r->right, k);
    k--;
    return k;

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

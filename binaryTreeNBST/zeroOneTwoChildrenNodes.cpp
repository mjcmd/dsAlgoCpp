
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
int* zeroOneTwoChildrenNodes(node* root, int* cnt);
int main()
{
    node* root;
    root=buildTree();
    int ct[3]={0};
    int* cnt=zeroOneTwoChildrenNodes(root, ct);

    cout<<cnt[0]<<" "<<cnt[1]<<" "<<cnt[2]<<endl;
    return 0;
}
int* zeroOneTwoChildrenNodes(node* root, int* cnt)
{
    //base condition for null node
    if(root==NULL)
        return cnt;

        //processing on node in preOrder fashion
    if(root->left==NULL&&root->right==NULL)
    {
        cnt[0]++;
    }
    if(root->left==NULL&&root->right!=NULL)
    {
        cnt[1]++;
    }
    if(root->left!=NULL&&root->right==NULL)
    {
        cnt[1]++;
    }
    if(root->left!=NULL&&root->right!=NULL)
    {
        cnt[2]++;
    }
    //recursively solve/check for other nodes
    cnt=zeroOneTwoChildrenNodes(root->left,  cnt);
    cnt=zeroOneTwoChildrenNodes(root->right,  cnt);

    //finally return the updated/calculated result
    return cnt;

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


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
node* bstFromSortedArray(int *ar, int s, int e);
void printPre(node* root);
int main()
{
    node* root;
    int ar[]={1, 2, 3, 4, 5};
    int m=sizeof(ar)/sizeof(ar[0]);
    root = bstFromSortedArray(ar, 0, m-1);
    printPre(root);
    return 0;
}
node* bstFromSortedArray(int *ar, int s, int e)
{
    if(s==e)
    {
        return new node(ar[s]);
    }
    if(s>e)
    {
        return NULL;
    }

    int mid=(s+e)/2;

    node* root=new node(ar[mid]);
    root->left=bstFromSortedArray(ar, s, mid-1);
    root->right=bstFromSortedArray(ar, mid+1, e);
    return root;
}
void printPre(node* root)
{
    if(!root)
    {
        return;
    }
    cout<<root->data<<" ";

    printPre(root->left);
    printPre(root->right);
}

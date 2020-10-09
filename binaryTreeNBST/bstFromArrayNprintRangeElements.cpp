
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
void bstFromArrayNprintRangeElements(int *ar, int m, int K1, int K2);
int main()
{
    node* root;
    int ar[]={1, 2, 3, 4, 5, 6, 7, 8 , 9};
    int m=sizeof(ar)/sizeof(ar[0]);
    bstFromArrayNprintRangeElements(ar, m, 5, 6);
    return 0;
}
node* insertBst(node* root, int x)
{
    if(root==NULL)
    {
        return new node(x);
    }

    if(x<root->data)
    {
       root->left=insertBst(root->left, x);
    }
    else
    {
        root->right=insertBst(root->right, x);
    }
    return root;
}
node* makeTree(node* root, int* ar, int m)
{

    for(int i=0; i<m; i++)
    {
        root=insertBst(root, ar[i]);
    }
    return root;
}
void printK1toK2(node* root, int K1, int K2)
{
    if(root==NULL)
    {
        return;
    }
    if(root->data>=K1&&root->data<=K2)
        cout<<root->data<<" ";
    printK1toK2(root->left, K1, K2);
    printK1toK2(root->right, K1, K2);
}
void bstFromArrayNprintRangeElements(int *ar, int m, int K1, int K2)
{
    node* root=NULL;
    root=makeTree(root, ar, m);

    printK1toK2(root, K1, K2);
}

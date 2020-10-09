
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
void printPre(node* root);
int replaceEachNodebySumofChildNodes(node*& root);
int main()
{
    node* root;
    root=buildTree();
    int data=replaceEachNodebySumofChildNodes(root);
    printPre(root);
    return 0;
}
int replaceEachNodebySumofChildNodes(node*& root)
{
    if(!root)
    {
        return 0;
    }
    if(!root->left&&!root->right)
    {
        return root->data;
    }

        int s1 = replaceEachNodebySumofChildNodes(root->left);
        int s2 = replaceEachNodebySumofChildNodes(root->right);
        int temp = root->data;
        root->data=s1+s2;
        return s1+s2+temp;


        /*
    if(root->left&&root->right)
    {
        int s1 = replaceEachNodebySumofChildNodes(root->left);
        int s2 = replaceEachNodebySumofChildNodes(root->right);
        int temp = root->data;
        root->data=s1+s2;
        return s1+s2+temp;

    }
    if(root->left)
    {
        int s1=replaceEachNodebySumofChildNodes(root->left);
        int temp = root->data;
        root->data=s1;
        return s1+temp;
    }
    if(root->right)
    {
        int s2=replaceEachNodebySumofChildNodes(root->right);
        int temp = root->data;
        root->data=s2;
        return s2+temp ;
    }

*/
   // return s1+s2;
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

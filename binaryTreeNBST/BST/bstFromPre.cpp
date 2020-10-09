


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
node* bstFromPre(vector<int> pre, int s, int e);
void preOrder(node* root)
{
    if(!root)
    {
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
int main()
{
    node* root;
    //root=buildBst();
    vector<int> pre={5, 3, 1, 7, 6, 8};

    root = bstFromPre(pre, 0, pre.size()-1);
    preOrder(root);

    return 0;
}
node* bstFromPre(vector<int> pre, int s, int e)
{
    if(s>e)
    {
        return NULL;
    }
    else if(s==e)
    {
        return new node(pre[s]);
    }
    else
    {
        node* tmp=new node(pre[s]);

        int j=s+1;
        while(pre[j]<=pre[s])
        {
            j++;
        }

        tmp->left=bstFromPre(pre, s+1, j-1);
        tmp->right=bstFromPre(pre, j, e);
        return tmp;
    }
}

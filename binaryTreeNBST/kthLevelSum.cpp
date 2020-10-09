



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
int kthLevelSum(node* root, int level);
int main()
{
    node* root;
    int k;
    cin>>k;
    root=buildTree();
    cout<<kthLevelSum(root, k);
    return 0;
}
int kthLevelSum(node* root, int level)
{
    queue<node*>   q;
    node* null=NULL;
    q.push(root);
    q.push(null);

    int l=1;
    if(level==1)
        return root->data;
    while(!q.empty())
    {
        if(!q.front())
        {
            l++;
            if(level==l)
            {
                q.push(null);
                int sum=0;
                q.pop();
                node* tmp=q.front();
                while(tmp)
                {
                    sum=sum+tmp->data;
                    q.pop();
                    tmp=q.front();
                }
                return sum;
            }
            q.pop();
            if(q.empty())
                break;
            q.push(null);
            continue;
        }
        node* f=q.front();
        q.pop();

        if(f->left)
            q.push(f->left);
        if(f->right)
            q.push(f->right);
    }
    return -1;
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

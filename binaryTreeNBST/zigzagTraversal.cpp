
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
void zigzagTraversal(node* root);
int main()
{
    node* root;
    root=buildTree();
    zigzagTraversal(root);
    return 0;
}


void zigzagTraversal(node* root)
{
    queue<node*>   q;
    stack<node*> s;
    node* null=NULL;
    q.push(root);
    q.push(null);
    int l=0;
    while(!q.empty())
    {

        node* f=q.front();
        q.pop();
        if(f!=NULL)
        {
            if(l&1)
            {
               s.push(f);
                if(!q.front())
                {
                    while(!s.empty())
                    {
                        node* tp=s.top();
                        cout<<tp->data<<" ";
                        s.pop();
                    }
                }
            }
            else
            {
                cout<<f->data<<" ";
            }
        }
        else
        {
            l++;
            cout<<endl;
            q.push(null);
            if(q.front()==NULL)
                break;
            continue;
        }

        if(f->left)
            q.push(f->left);
        if(f->right)
            q.push(f->right);
    }
    return;
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

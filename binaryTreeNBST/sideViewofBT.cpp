


#include<bits/stdc++.h>
#include<map>
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
void rightSideViewofBT(node* root);
void leftSideViewofBT(node* root);
node* buildTree(void);

int main()
{
    node* root;
    root=buildTree();
    rightSideViewofBT(root);
    //leftSideViewofBT(root);
    return 0;
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

void leftSideViewofBT(node* root)
{
    queue<node*>   q;
    node* null=NULL;
    q.push(null);
    q.push(root);

    while(!q.empty())
    {
        node* popped=q.front();

        q.pop();
        if(!popped)
        {
            if(q.empty()!=true)
                cout<<q.front()->data<<endl;

            q.push(NULL);
            if(!q.front())
                break;
        }
        else
        {
            if(popped->left)
                q.push(popped->left);
            if(popped->right)
                q.push(popped->right);
        }
    }
    return;

}


void rightSideViewofBT(node* root)
{
    queue<node*>   q;
    node* null=NULL;
    q.push(root);
    q.push(null);

    while(!q.empty())
    {
        node* popped=q.front();

        q.pop();

        if(!popped)
        {
            q.push(NULL);
            if(q.front()==NULL)
                break;
        }
        else
        {
            if(!q.front())
                cout<<popped->data<<endl;

            if(popped->left)
                q.push(popped->left);
            if(popped->right)
                q.push(popped->right);
        }
    }
    return;
}

#include<bits/stdc++.h>
#include<queue>
#include<algorithm>
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
void levelOrderPrintWithQueue(node* root);
void levelOrderPrintWithQueue2(node* root, vector<int> level);
void levelOrderPrintWithQueueEndl(node* root);
void levelOrder(node* root);
int height(node* root);
int main()
{
    node* root;
    vector<int> level ={0, 1, 1, 2};
    root=buildTree();
    //levelOrderPrintWithQueue(root);
    //cout<<height(root);
    //levelOrder(root);
    //levelOrderPrintWithQueue2(root, level);
    levelOrderPrintWithQueueEndl(root);
    return 0;
}

void levelOrderPrintWithQueueEndl(node* root)
{
    queue<node*>   q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node* popped=q.front();
        q.pop();
        if(popped!=NULL)
        {
            cout<<popped->data<<" ";
            if(popped->left)
                q.push(popped->left);
            if(popped->right)
                q.push(popped->right);

        }
        else
        {
            cout<<endl;
            q.push(NULL);
            if(q.front()==NULL)
                break;
        }

    }
    return;
}
void levelOrderPrintWithQueue2(node* root, vector<int> level)
{
    queue<node*>   q;
    q.push(root);

     int i=0, c=0;
    while(!q.empty())
    {

        while(c==level[i])
        {
            node* f=q.front();
            cout<<f->data<<" ";

        q.pop();
        if(f->left)
            q.push(f->left);
        if(f->right)
            q.push(f->right);

            i++;
        }
        cout<<endl;
        c++;

    }
    return;
}
void levelOrderPrintWithQueue(node* root)
{
    queue<node*>   q;

    q.push(root);

    while(!q.empty())
    {
        node* f=q.front();
        cout<<f->data<<" ";

        q.pop();
        if(f->left)
            q.push(f->left);
        if(f->right)
            q.push(f->right);
    }
    return;
}
int height(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return max(height(root->left), height(root->right));
}
void printHelper(node* root, int L)
{
    if(!root)
    {
        return;
    }
    if(L==0)
    {
        cout<<root->data<<" ";
    }
    printHelper(root->left, L-1);
    printHelper(root->right, L-1);

}

void levelOrder(node* root)
{
    int lastLevel=height(root);
    for(int L=0; L<lastLevel; L++)
    {
        printHelper(root, L);
        cout<<endl;
    }
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


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
int main()
{
    node* root;
    root=buildTree();
    printBinaryTree(root);
    return 0;
}
void printBinaryTree(node* root)
{
    queue<node*>   q;
    queue<node*>   q2;
    q.push(root);
    q.push(NULL);
    int k=50;

    k=k-2;
    int j=k;
    for( ; j>0; j=j-1)
        cout<<" ";
    while(!q.empty())
    {
        node* popped=q.front();
        q.pop();
        if(popped!=NULL)
        {
            q2.push(popped);
            cout<<popped->data<<"   ";//<<"/ "<<"\\";
            if(popped->left)
                q.push(popped->left);
            if(popped->right)
                q.push(popped->right);

        }
        else
        {
            cout<<endl;
            k=k-2;
            int j=k;
            for( ; j>0; j=j-1)
                cout<<" ";
            while(!q2.empty())
            {
                node* tmp = q2.front();
                if(tmp->left)
                {
                    cout<<"/ ";
                }
                if(tmp->right)
                {
                    cout<<"\\";
                }
                q2.pop();
            }
            cout<<endl;
            k=k-3;
            j=k;
            for( ; j>0; j=j-1)
                cout<<" ";

            q.push(NULL);
            if(q.front()==NULL)
                break;
        }

    }


    /*
    if(root!=NULL)
        cout<<root->data<<endl;
    if(root->left)
    {
        cout<<"/ ";
        printBinaryTree(root->left);
    }
    if(root->right)
    {
        cout<<"\\"<<endl;
        printBinaryTree(root->right);
    }
    */
    return ;
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

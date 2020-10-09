
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
class linkedList
{
public:
    node* head;
    node* tail;
};
node* buildBst(void);
linkedList flattenBst(node *root);
int main()
{
    node* root;
    root=buildBst();
    linkedList ll=flattenBst(root);

    node* tmp=ll.head;
    while(tmp!=NULL)
    {
        cout<<tmp->data<<"-~>";
        tmp=tmp->right;
    }
    return 0;
}
linkedList flattenBst(node *root)
{
    linkedList l;
    if(!root)
    {
        l.head=l.tail=NULL;
        return l;
    }
    else if(!root->left&&!root->right)
    {
        l.head=l.tail=root;
        return l;
    }
    else if(!root->right)
    {
        linkedList leftll= flattenBst(root->left);
        leftll.tail->right=root;

        l.head=leftll.head;
        l.tail=root;
        return l;
    }
    else if(!root->left)
    {
        linkedList rightll= flattenBst(root->right);
        root->right=rightll.head;

        l.head=root;
        l.tail=rightll.tail;
        return l;
    }
    else
    {
        linkedList leftll= flattenBst(root->left);
        linkedList rightll= flattenBst(root->right);

        leftll.tail->right=root;
        root->right=rightll.head;

        l.head=leftll.head;
        l.tail=rightll.tail;
        return l;
    }

}
node* insertBst(node* root, int d)
{
    if(!root)
    {
        return new node(d);
    }
    if(d<root->data)
    {
        root->left=insertBst(root->left, d);
    }
    else
    {
        root->right=insertBst(root->right, d);
    }
    return root;
}
node* buildBst(void)
{
    node* root=NULL;
    int d;
    cin>>d;
    while(d!=-1)
    {
        root = insertBst(root, d);
        cin>>d;
    }
    return root;
}

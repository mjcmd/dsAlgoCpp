
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
map<int, list<node*>> verticalOrderTraversal(node* root);
node* replaceAllNodesWithSumofNodesgreaterEqualtoIt(node* root)

int main()
{
    node* root;
    root=buildTree();
    root=replaceAllNodesWithSumofNodesgreaterEqualtoIt(root);
    return 0;
}
node* replaceAllNodesWithSumofNodesgreaterEqualtoIt(node* root)
{

}
map<int, list<node*>> verticalOrderTraversal(node* root)
{
    queue <pair<int, node*> > q;
    pair<int, node*> p={0, root};
    q.push(p);

    map<int, list<node*>>sol;
    while(!q.empty())
    {
        p=q.front();
        q.pop();
       // if(sol.find(p.first)==end())
        {
            sol[p.first].push_back(p.second);
        }

        if(p.second->left)
        {
            q.push(std::make_pair(p.first-1, p.second->left));
        }
        if(p.second->right)
        {
            q.push(std::make_pair(p.first+1, p.second->right));
        }

    }
    return sol;
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

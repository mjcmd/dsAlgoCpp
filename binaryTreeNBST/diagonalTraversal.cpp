
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

node* buildTree(void);

map<int, list<node*>> diagonalTraversal(node* root);
void printMap(map<int, list<node*>>Map);
int main()
{
    node* root;
    root=buildTree();
    map<int, list<node*>>Map=diagonalTraversal(root);
    printMap(Map);

    return 0;
}
map<int, list<node*>> diagonalTraversal(node* root)
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
            q.push(std::make_pair(p.first+1, p.second->left));
        }
        if(p.second->right)
        {
            q.push(std::make_pair(p.first, p.second->right));
        }

    }
    return sol;
}
void printMap(map<int, list<node*>>Map)
{
    for(auto ele: Map)
      {
         cout<<ele.first<<"->";
         for(auto &el: ele.second)
             cout<<el->data;
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

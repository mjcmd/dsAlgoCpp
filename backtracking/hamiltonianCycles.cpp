
#include<bits/stdc++.h>

using namespace std;

// A utility function to add an edge in an
// undirected graph.
void addEdge(vector<int>* adj, int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void print(vector<int> sol)
{
        for (int j = 0; j < sol.size(); j++)
            cout<<sol[j]<<" ";
        cout<<endl;
}

int V=5;
void hamiltonianCycles(vector<int>* adj, vector<int> sol, int i, int level);



int main()
{
    int i = 0;
    vector<int> sol;
    sol.push_back(0);
    vector<int> adj[V];

    // Vertex numbers should be from 0 to 4.
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 4);
    addEdge(adj, 3, 4);

    hamiltonianCycles( adj, sol, i, 1);

    return 0;
}

bool isDuplicate(vector<int> sol, int i)
{
    for(int k = 0; k<sol.size(); k++)
    {
        if(sol[k]==i)        //duplicate found
            return true;
    }

    return false;
}

bool connectedWithPrevVert(vector<int>* adj, vector<int> sol, int i)
{
    for(int k = 0; k<adj[i].size(); k++)
    {
        if(adj[sol[sol.size()-1]][k]==i)        //sol[size-1]/prevVertex---edge---ith vertex ...found edge
            return true;
    }
    return false;
}
bool connectedWithFirstV(vector<int>* adj, int i)
{
        for(int k = 0; k<adj[0].size(); k++)
        {
            if(adj[0][k]==i)        //found edge from i to vert 0
                return true;
        }

    return false;
}
bool isConstraintsSatisfying(vector<int>* adj, vector<int> sol, int i, int level)
{
    if(level==4)
        return !isDuplicate(sol, i)&&connectedWithPrevVert(adj, sol, i)&&connectedWithFirstV(adj, i);
    else
        return !isDuplicate(sol, i)&&connectedWithPrevVert(adj, sol, i);
}
void hamiltonianCycles(vector<int>* adj, vector<int> sol, int i, int level)
{
    if(level==5)
    {
        sol.push_back(0);
        print(sol);
        return;
    }
    for(int k = 0; k<adj[i].size(); k++)
    {
        if(isConstraintsSatisfying(adj, sol, adj[i][k], level) )
        {
            sol.push_back(adj[i][k]);
            hamiltonianCycles(adj, sol, adj[i][k], level+1);

            sol.pop_back();
        }
    }
    return;
}

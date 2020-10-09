#include<bits/stdc++.h>
#define V 4
using namespace std;

void addEdge(vector<int>* adj, int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void print1(vector<char> sol)
{
     for(int i =0; i<V; i++)
                {
                    cout<<sol[i];
                    /*
                    for(int j =0; j<adj[i].size(); j++)
                    {
                        cout<<adj[i][j]<<" ";
                    }
                    cout<<endl; */
                }
}
//int V=5;
bool graphColoring(vector<int>* adj,  vector<char> sol,vector<char> color, int i, int level);

bool isAdj(vector<int>* adj, int vert, int k)
{
    for(int i=0; i<adj[vert].size(); i++)
    {
        if(adj[vert][i]==k)
            return true;
    }
    return false;
}
bool sameColor(char color, char kthVertColor)
{
    if(color==kthVertColor)
        return true;
    return false;
}
bool isValidColor(vector<int>* adj, vector<char> sol, int vert, char color)
{

        for(int k=0; k<sol.size(); k++)
            {
                //cout<<k;
               if(isAdj(adj, vert, k)&&sameColor(color, sol[k]))  //checking vert is adjacent to kth vertex in sol && vert-color compared with kth vertex color
                    return false;
                //cout<<endl;
            }
    return true;
}

int main()
{
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);
    addEdge(adj, 1, 2);
    //addEdge(adj, 1, 3);
    //addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    //addEdge(adj, 3, 4);
    //print1(adj);
    //vector<vector<int>> g(2, vector<int> (6)) ;
     /*               {{1, 3, 5},
                      {0, 2},
                      {1, 3, 0, 1},
                      {0, 2},
                      {2}
                    }; */

                vector<char> color={'R', 'G', 'B'}, sol;
               sol.push_back(color[0]);
                //sol.push_back(color[1]);
   if(graphColoring(adj, sol, color, 0,  0))
    cout<<"solution found!";
   else
    cout<<"No solution!";
   //cout<<isAdj(adj, 2, 1);
   //cout<<sameColor('R', sol[1]);
   //cout<<isValidColor(adj, sol, 3, 'G');
    //print2();


    return 0;
}

void print2(vector<char> sol)
{
    for(int i=0; i<sol.size(); i++)
        cout<<sol[i];
    cout<<endl;
}
bool graphColoring(vector<int>* adj, vector<char> sol, vector<char> color, int i,  int level)
{
    //cout<<level;
    if(level==3)
    {
        print2(sol);
        return true;
    }

    for(int adjVert=0; adjVert<adj[i].size(); adjVert++)
    {
        for(int c = 0; c<color.size(); c++)
        {
            //cout<<adjVert<<" "<<color[c]<<endl;
            if(isValidColor(adj, sol, adj[i][adjVert], color[c]))
            {

                sol.push_back(color[c]);
                //cout<<"s";
                if(graphColoring(adj, sol, color, adj[i][adjVert], level+1))
                    return true;

                sol.pop_back();
            }
        }
    }

    return false;
}



#include<iostream>
#include<bits/stdc++.h>

using namespace std;

/*
class Graph//is not generic ie not suitable for string datatype nodes
{
    int V;
    list<int> *l;    //

public:
    Graph(int v)
    {
        V=v;
        //Array of linked lists
        l=new list<int>[v];
    }
    void addEdge(int u, int v, bool bidir=true)
    {
        l[u].push_back(v);
        if(bidir)
        {
            l[v].push_back(u);
        }
    }
    void printAdjList()
    {
        for(int i=0; i<V; i++)
        {
            cout<<i<<"->";
            for(int vert: l[i])
            {
                cout<<vert<<", ";
            }
            cout<<endl;

        }
    }

};*/


template<typename T>
class Graph
{
    map<T, list<T>> adjList;
public:
    Graph()
    {

    }
    void addEdge(T u, T v, bool bidir=true)
    {
        adjList[u].push_back(v);
        if(bidir)
        {
            adjList[v].push_back(u);
        }
    }
    void print()
    {
        for(auto i: adjList)
        {
            cout<<i.first<<"->";

            for(T e: i.second)
            {
                cout<<e<<", ";
            }
            cout<<endl;
        }
    }
    void dfsHelper(T node, map<T, bool>&visited)
    {
        cout<<node<<" ";


        visited[node]=true;

        for(T neigbour: adjList[node])
        {
            if(!visited[neigbour])
            {
                dfsHelper(neigbour, visited);
            }
        }

    }
    void dfs(T s)
    {
        map<T, bool> visited;
        dfsHelper(s, visited);
        int component=1;
        cout<<endl;
        for(auto e: adjList)
        {
            T city=e.first;
            if(!visited[city])
            {
                dfsHelper(city, visited);
                component++;
                cout<<endl;
            }
        }
        cout<<"Graph contains "<<component<<" components"<<endl;
    }
    void bfs(T s)
    {

        map<T, int> dist;
        for(auto e: adjList)
        {
            dist[e.first]=INT_MAX;
        }
        dist[s]=0;
        //map<T, bool> visited;
        queue<T> q;

        q.push(s);
        //visited.insert({s, true});

        while(!q.empty())
        {
            T node=q.front();
            q.pop();
            //cout<<node<<" ";

            for(T e: adjList[node])
            {
                if(dist[e]==INT_MAX)
                {
                    dist[e]=dist[node]+1;
                    q.push(e);
                    //visited[e]=true;
                }
            }
        }

        //dist from source
        for(auto e: dist)
        {
            cout<<e.first<<" from "<<s<<" "<<e.second<<endl;
        }
    }


};



int main()
{
    Graph<string> g;

    g.addEdge("A", "J");
    g.addEdge("A", "D");
    g.addEdge("D", "J");
    g.addEdge("M", "J");
    g.addEdge("M", "B");
    g.addEdge("D", "B");
    g.addEdge("M", "BL");
    g.addEdge("AG", "D");
    g.addEdge("AN", "N");
    g.dfs("A");


    /*
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(4, 3);
    g.addEdge(1, 4);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.bfs(0);
    */

    //g.printAdjList();
    /*
    //for Graph by hashmap
    Graph<string> g;
    g.addEdge("Putin", "Trump", false);
    g.addEdge("Putin", "Modi", false);
    g.addEdge("Putin", "Pope", false);
    g.addEdge("Modi", "Trump", true);
    g.addEdge("Modi", "Yogi", true);
    g.addEdge("Yogi", "Prabhu", false);
    g.addEdge("Prabhu", "Modi", false);
    g.print();

    cout<<endl;

    Graph<int> g2;
    g2.addEdge(1, 2);
    g2.addEdge(100, 2);
    g2.addEdge(100, 3);
    g2.print();
    */
    return 0;
}

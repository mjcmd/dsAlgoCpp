#include<iostream>
#include<bits/stdc++.h>

using namespace std;


template<typename T>
class graph
{
    unordered_map<T, list< pair<T, int> >> adjList;
public:
    graph()
    {

    }
    void addEdge(T u, T v, int dist, bool bidir=true)
    {
        adjList[u].push_back(make_pair(v, dist));
        if(bidir)
        {
            adjList[v].push_back(make_pair(u, dist));
        }
    }
    void print()
    {
        for(auto i: adjList)
        {
            cout<<i.first<<"->";

            for(auto p: i.second)
            {
                cout<<"("<<p.first<<":"<<p.second<<") ";
            }
            cout<<endl;
        }
    }

    void dijkstraSSSP(T src)
    {
        unordered_map<T, int> dist;

        for(auto& e: adjList)
        {
            dist[e.first]=INT_MAX;
        }

        set<pair<int, T>>s;
        dist[src]=0;
        s.insert({0, src});

        while(!s.empty())
        {
            auto currentSmall=*(s.begin());
            T u=currentSmall.second;
            auto dist_u=currentSmall.first;

            s.erase(s.begin());

            for(auto p: adjList[u])
            {
                auto cost_uv=p.second;
                auto v=p.first;
                if(dist_u+cost_uv<dist[v])
                {
                    auto f=s.find(make_pair(dist[v], v));
                    if(f!=s.end())
                    {
                        s.erase(f);
                    }
                    dist[v]=dist_u+cost_uv;
                    s.insert(make_pair(dist[v], v));
                }
            }

        }

        //let's print the distances to all other nodes from src
        for(auto d: dist)
        {
            cout<<d.first<<" is located at a distance of "<<d.second<<endl;
        }

    }



};

int main()
{
    graph<int> india;
    india.addEdge(1, 2, 1);
    india.addEdge(1, 3, 4);
    india.addEdge(2, 3, 1);
    india.addEdge(3, 4, 2);
    india.addEdge(1, 4, 7);
    india.dijkstraSSSP(1);

    /*
graph<string> india;

    india.addEdge("Amritsar", "Delhi", 1 );
    india.addEdge("Amritsar", "jaipur", 4);
    india.addEdge("jaipur", "Delhi", 2);
    india.addEdge("jaipur", "Mumbai", 8);
    india.addEdge("Bhopal", "Agra", 2);
    india.addEdge("Mumbai", "Bhopal", 3);
    india.addEdge("Agra", "Delhi", 1);
    //india.print();
    india.dijkstraSSSP("Amritsar");
    */
    return 0;
}

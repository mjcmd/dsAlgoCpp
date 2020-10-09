#include<iostream>
#include<bits/stdc++.h>

#define INT_MAX 999999

using namespace std;


template<typename T>
class edgeList
{
    class edge
    {
        public:
        T u;
        T v;
        int w;
    }edgee;

    map<T, bool>vertices;
    vector<edge> edgeLis;
public:

    void addEdge(T x, T y, int wei, bool bidir=true)
    {
        edgee.u=x;
        edgee.v=y;
        edgee.w=wei;
        edgeLis.push_back(edgee);
        if(bidir)
        {
            edgee.u=y;
            edgee.v=x;
            edgee.w=wei;
            edgeLis.push_back(edgee);
        }

        if(vertices.find(x)==vertices.end())
        {
            vertices.insert({x, true});
        }
        if(vertices.find(y)==vertices.end())
        {
            vertices.insert({y, true});
        }
    }

    void print(void)
    {
        for(auto e: edgeLis)
        {
            cout<<e.u<<" "<<e.v<<" "<<e.w<<endl;
        }
    }

    void bellmanFord(T src)
    {
        map<T, int> d;
        for(auto p: vertices)
            {
                d.insert({p.first, INT_MAX});
            }
        d[src]=0;

        for(int i=1; i<=vertices.size()-1; i++)
        {
            for(edge e: edgeLis)
            {
                if(d[e.u]+e.w<d[e.v])
                {
                    d[e.v]=d[e.u]+e.w;
                }
            }
            for(auto el: d)
            {
                cout<<"shortest distance from "<<src<<" to "<<el.first<<" : "<<el.second<<endl;
            }
            cout<<endl;
        }

        for(edge e: edgeLis)
            {
                if(d[e.u]+e.w<d[e.v])
                {
                    cout<<"negative weight cycle exist!";
                    return;
                }
            }
        //print shortest distances from sourc to all other vertices;
        for(auto el: d)
        {
            cout<<"shortest distance from "<<src<<" to "<<el.first<<" : "<<el.second<<endl;
        }

    }


};

int main()
{
    /*
    edgeList<int>g;
    g.addEdge(1, 2, 6);
    g.addEdge(1, 3, 5);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 5, -1);
    g.addEdge(3, 2, -2);
    g.addEdge(3, 5, 1);
    g.addEdge(4, 3, -2);
    g.addEdge(4, 6, -1);
    g.addEdge(5, 7, 3);
    g.addEdge(6, 7, 3);
    */


    edgeList<string> g;
    //g.addEdge("A", "B", -1, false);  //for directed graph
    //g.addEdge("A", "B", -1, true);  //for un-directed graph
    //g.addEdge("A", "B", 1, false);   //for directed as well as un direceted graph
    g.addEdge("A", "B", 1, true);      //of positive edges, BF works!

    //g.addEdge(4, 3, 3);

    //g.print();


    g.bellmanFord("A");
    return 0;
}

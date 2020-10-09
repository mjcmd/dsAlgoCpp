#include<iostream>
#include<bits/stdc++.h>
#define N 4
#define INT_MAX 999999

using namespace std;

int dist[10][10]={{0, 20, 42, 25},
                  {20, 0, 30, 34},
                  {42, 30, 0, 10},
                  {25, 34, 10, 0}
};
int VISITED_ALL=(1<<N)-1;


int tsp(int mask, int pos)
{
    if(mask==VISITED_ALL)
    {
        return dist[pos][0];
    }

    int minAns=INT_MAX;
    //cout<<minAns;
    for(int city=0; city<N; city++)
    {
        //cout<<"sumil"<<endl;
        int ithCity=1<<city;
        int visited=mask&ithCity;
        if(visited==0)
        {
            int ans=dist[pos][city]+tsp(mask|(1<<city), city);
            minAns=min(minAns, ans);
            //cout<<minAns<<endl;
        }
    }
    //cout<<minAns<<endl;
    return minAns;
}
int main()
{
    int mask=1, ithcity=1 ;
    int ithCity=(1<<ithcity);
    //cout<<y;
    int visited=mask&ithCity;
    //cout<<z;
    int x=visited==0;
    //cout<<x;
    cout<<tsp(1, 0)<<endl;
    return 0;
}

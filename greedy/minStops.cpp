#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class df
{
    public:
    int d;
    int f;
};

int minStops(df* p, int N, int L, int P);
int main()
{
    int N;
    cin>>N;
    df p[N+1];
    for(int i=1; i<=N; i++)
        cin>>p[i].d>>p[i].f;        //d[i] dist from destination town to stop i, f[i] fuel available at stop i

    int L, P;
    cin>>L>>P;
    p[0].d=0; p[0].f=P;

    cout<<minStops(p, N, L, P)-1;
    return 0;
}
bool compfuel(df a, df b)
{
    return a.f>b.f;
}
int minStops(df* p, int N, int L, int P)
{
    int minStop=0;
    for(int i=1; i<=N; i++)
        p[i].d=L-p[i].d; //d[i] dist from curr location of truck
    sort(p+1, p+N+1, compfuel);

    int petrolNow=P;
    int location=P;

    int i=0;
    while(location<=L)
    {
        if(p[i+1].d-p[i].d<=petrolNow)
        {
            petrolNow=petrolNow-(p[i+1].d-p[i].d)+p[i+1].f;
            location=location+p[i+1].f;
            minStop++;
            i++;
        }
        else
        {
            return 0;
        }

    }
    return minStop;
}

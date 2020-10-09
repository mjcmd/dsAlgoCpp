#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int grandTempleArea(pair<int, int>* p, int m);

int main()
{
    int m;
    cin>>m;
    pair<int, int> p[m];
    for(int i=0; i<m; i++)
    {
        cin>>p[i].first>>p[i].second;
    }
    cout<<grandTempleArea(p, m);
    return 0;
}
bool compX(pair<int, int>p1, pair<int, int>p2 )
{
    return p1.first<p2.first;
}
int grandTempleArea(pair<int, int>* p, int m)
{
    sort(p, p+m, compX);
    int maxArea=INT_MIN;
    int i=0;
    while(i<=m-2)
    {
        int area=abs(abs(p[i].first-p[i+1].first)-1)*(abs(p[i].second-p[i+1].second)-1);
        if(maxArea<area)
        {
            maxArea=area;
        }
        i++;
    }
    return maxArea;
}

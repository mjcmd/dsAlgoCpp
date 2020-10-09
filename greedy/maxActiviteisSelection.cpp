#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class activity
{
    public:
    string name;
    int ST;
    int FT;
} ;
void maxActivitiesSelection(activity* a, int n);

int main()
{
    int n;
    cin>>n;
    activity a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i].name>>a[i].ST>>a[i].FT;
    }
    /*
    a[0].name="A1";
    a[0].ST=12;
    a[0].FT=25;

    a[1].name="A2";
    a[1].ST=10;
    a[1].FT=20;

    a[2].name="A3";
    a[2].ST=20;
    a[2].FT=30;
    */
    maxActivitiesSelection(a, n);
    return 0;
}
bool comp(activity a, activity b)
{
    return a.FT<b.FT;
}
void maxActivitiesSelection(activity* a, int n)
{
    sort(a, a+n, comp);
    int i=0, prev=0;
    cout<<a[0].name<<" ";
    while(i<=n-2)
    {
        if(a[prev].FT<=a[i+1].ST)
        {
            cout<<a[i+1].name<<" ";
            prev=i+1;
        }

        i++;
    }
}

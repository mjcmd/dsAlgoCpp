#include<iostream>
#include<bits/stdc++.h>

using namespace std;
void leftmaxRightmax(vector<int>A);

void leftmax(vector<int> A, int s, int e);
void rightmax(vector<int> A, int s, int e);
std::map<int, pair<int, int>> M;
int main()
{
    vector<int> A;
    int d;
    cin>>d;
    while(d!=-1)
    {
        A.push_back(d);
        cin>>d;
    }

    leftmaxRightmax(A);
    //leftmax(A, 0, A.size()-2);
    //rightmax(A, 1, A.size()-1);

    for(auto e: M)
    {
        cout<<e.first<<" : "<<e.second.first<<", "<<e.second.second<<endl;
    }
    return 0;
}
void leftmaxRightmax(vector<int>A)
{
    leftmax(A, 0, A.size()-2);
    rightmax(A, 1, A.size()-1);
}
void leftmax(vector<int> A, int s, int e)
{
    static int mpos=e+1;
    if(s>e)
    {
        return ;
    }
    if(s==e)
    {
        M[A[s+1]].first=A[s];
    }

    int mx=INT_MIN;
    for(int i=s; i<=e; i++)
    {
        if(mx<A[i])
        {
            mx=A[i];
            mpos=i;
        }

    }
    int k=mpos+1;
    while(k<=e+1)
    {
        M[A[k]].first=A[mpos];
        k++;
    }

    leftmax(A, s, mpos-1);
    return;
}
void rightmax(vector<int> A, int s, int e)
{
    static int mpos=0;
    if(s>e)
    {
        return ;
    }
    if(s==e)
    {
        M[A[s-1]].second=A[s];
    }

    int mx=INT_MIN;
    for(int i=s; i<=e; i++)
    {
        if(mx<A[i])
        {
            mx=A[i];
            mpos=i;
        }

    }
    int k=s-1;
    while(k!=mpos)
    {
        M[A[k]].second=A[mpos];
        k++;
    }

    rightmax(A, mpos+1, e);
    return;
}
/*
int qmax(priority_queue<int> q)
{
    if(q.empty())
        return -1;
    else
        return q.top();
}
void leftmaxRightmax(vector<int> A, int n)
{
    priority_queue<int, vector<int>, less<int>> qleft, qright;
    int i=0;
    while(i<A.size())
    {
        qright.push(A[i]);
        i++;
    }
    int c;

    for(int i=0; i<A.size(); i++)
    {
        cout<<c<<" : "<<qmax(qleft)<<", "<<qmax(qright)<<endl;
        qleft.push(c);
        c=qright.top(); qright.pop();
    }
}
*/

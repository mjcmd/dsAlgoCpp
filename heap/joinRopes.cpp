#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int joinRopes(priority_queue<int,  vector<int>, greater<int>> ropes);

int main()
{
    priority_queue<int, vector<int>, greater<int>> ropes;
    int d;
    cin>>d;
    while(d!=-1)
    {
        ropes.push(d);
        cin>>d;
    }


    cout<<joinRopes(ropes)<<endl;
    for(; !ropes.empty();)
        {
            cout<<ropes.top()<<" "; ropes.pop();
        }
    return 0;
}
int joinRopes(priority_queue<int,  vector<int>, greater<int>> ropes)
{
    int rope1, rope2, c, cost=0;
    while(ropes.size()!=1)
    {
        rope1=ropes.top(); ropes.pop();
        rope2=ropes.top(); ropes.pop();

        int c=rope1+rope2;
        cost=cost+c;

        ropes.push(c);
    }
    return cost;
}

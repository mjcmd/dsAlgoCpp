#include<bits/stdc++.h>
using namespace std;

void input(queue<int>& q)
{
    int key;
    cin>>key;
    while(key!=-1)
    {
        q.push(key);
        cin>>key;
    }
}
int timeForNprocesses(queue<int> co, queue<int>io)
{
    int cost=0;
    while(!io.empty())
    {
        while(co.front()!=io.front())
            {
                int tmp=co.front();
                co.pop();
                co.push(tmp);
                cost++;
            }
        co.pop();
        cost++;
        io.pop();
    }
    return cost;
}
int main()
{
    queue<int> co;
    queue<int> io;
    input(co);
    input(io);

    cout<<timeForNprocesses(co, io)<<" units of time";
    return 0;
}

#include<bits/stdc++.h>
#include<queue>
#include<stack>

using namespace std;

void reverseQueueUsingStack(queue<int>&q);
void reverseQueueRec(queue<int>& q);
void input(queue<int>& q)
{
    int k;
    cin>>k;
    while(k!=-1)
    {
        q.push(k);
        cin>>k;
    }
}
void print(queue<int> q)
{
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
}

int main()
{
    queue<int> q;
    input(q);
    reverseQueueRec(q);
    //reverseQueueUsingStack(q);
    print(q);
    return 0;
}
void reverseQueueRec(queue<int>& q)
{
    if(q.empty())
    {
        return;
    }
    int f=q.front();
    q.pop();
    reverseQueueRec(q);
    q.push(f);
}
void reverseQueueUsingStack(queue<int>&q)      //using a stack
{
    stack<int> s;
    while(!q.empty())
    {
        s.push(q.front());
        q.pop();
    }
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
}

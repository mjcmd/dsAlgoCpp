#include<bits/stdc++.h>
using namespace std;
/*
class Queue
{
    int* arr;
    int f;
    int r;
    int cs;
    int ms;
public:

    Queue(int ds)
    {
        ms=ds;
        cs=0;
        arr= new int[ms];
        f=0;
        r=ms-1;
    }
    void Enque(int x)
    {
        if(Full())
            return;
        r=(r+1)%ms;
        arr[r]=x;
        cs++;


    }
    void Deque(void)
    {
        if(!Empty())
        {
            f=(f+1)%ms;
            cs--;
        }
    }
    int Front(void)
    {
        if(!Empty())
            return arr[f];
    }
    bool Empty(void)
    {
        return cs==0;
    }
    bool Full(void)
    {
        return cs==ms;
    }
};
*/

class Queue
{
private:
    stack<int> s1;
    stack<int> s2;
public:
    void push(int x)
    {
        s1.push(x);
    }
    void pop(void)
    {
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s2.pop();
        while(!s1.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    int front(void)
    {
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        int t= s2.top();
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return t;
    }
    bool empty(void)
    {
        return s1.empty();
    }

};
int main()
{

    /*Queue q(100);
    for(int i=1; i<=8; i++)
    {
        q.Enque(i);
    }
    q.Deque();
    q.Enque(9);
    q.Enque(10);
    for(; !q.Empty(); q.Deque())
    {
        cout<<q.Front()<<" ";
    }
    */
    Queue q;

    for(int i=0; i<5; i++)
    {
        q.push(i);
    }
     for(; !q.empty(); q.pop())
    {
        cout<<q.front()<<" ";
    }




    return 0;
}

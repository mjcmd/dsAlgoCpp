#include<bits/stdc++.h>
#include<stack>
using namespace std;

void input(stack<int>& s)
{
    int k;
    cin>>k;
    while(k!=-1)
    {
        s.push(k);
        cin>>k;
    }
}
void print(stack<int> s)
{
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}
void reverseStack1(stack<int>& s);
void reverseStackRec(stack<int>& s);
void reverseStack(stack<int>& s);

int main()
{
    stack<int> s;
    input(s);

    //reverseStack1(s);
    //reverseStackRec(s);
    reverseStack(s);
    print(s);
    return 0;
}
void insertAtBottom(stack<int>& s, int topElement)
{
    if(s.empty())
    {
        s.push(topElement);
        return;
    }
    int t=s.top();
    s.pop();
    insertAtBottom(s, topElement);
    s.push(t);

}

void reverseStackRec(stack<int>& s)        //reverse Stack using no Explicit stack
{
    if(s.empty())
    {
        return;
    }
    int topElement=s.top();
    s.pop();
    reverseStackRec(s);
    insertAtBottom(s, topElement);

    return;
}
void reverseStack1(stack<int>& s)              //reverse Stack using 1 explicit stack
{
    //cout<<s.size()<<endl;

    if(s.empty())
    {
        return;
    }
    stack<int> temp;
    int t=s.top();
    //cout<<t<<" ";
    s.pop();
    //print(s);
    reverseStack1(s);
    while(!s.empty())
    {
        temp.push(s.top());
        s.pop();
    }
    s.push(t);
    while(!temp.empty())
    {
        s.push(temp.top());
        temp.pop();
    }
    //print(s);
    cout<<endl;
    return;

}
void reverseStack(stack<int>& s)
{
    stack<int> tmp1, tmp2;

    while(!s.empty())
    {
        tmp1.push(s.top());
        s.pop();
    }
    while(!tmp1.empty())
    {
        tmp2.push(tmp1.top());
        tmp1.pop();
    }
    while(!tmp2.empty())
    {
        s.push(tmp2.top());
        tmp2.pop();
    }
}

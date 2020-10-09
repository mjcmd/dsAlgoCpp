#include<bits/stdc++.h>
#include "stack"
using namespace std;
/*
class Stack     //stack implemented using linkedList
{
    class node
    {
    public:
        int data;
        node* next;

        node(int x)
        {
            data=x;
            next=NULL;
        }
    };
    node* head;
    int sze;
public:
    Stack(void)
    {
        head=NULL;
        sze=0;
    }
    void push(int x)
    {
        node* t= new node(x);
        t->next=head;
        head=t;
        sze++;
    }
    void pop(void)
    {
        if(Empty())
            return;
        node* ahead=head->next;
        delete head;
        head=ahead;
        sze--;
    }
    int top(void)
    {
        if(Empty())
            return -1;

        return head->data;
    }
    bool Empty(void)
    {
        return head==0;
    }
    int Size(void)
    {
        return sze ;
    }
    ~Stack(void)
    {

        node* tmp;
        while(head)
        {
            tmp=head;
            head=head->next;
            delete tmp;
        }
    }

};
*/

/*
template<typename T>
class Stack
{
    vector<T> v;
public:
    void push(T key)
    {
        v.push_back(key);
    }
    void pop(void)
    {
        v.pop_back();
    }
    T top(void)
    {
        return v[v.size()-1];
    }
    bool Empty(void)
    {
        return(v.size()==0);
    }
    int Size(void)
    {
        return v.size();
    }
};
void print(Stack<int> s)
{
    while(!s.Empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}
*/

class Stack
{
    queue<int> q1;
    queue<int> q2;
    public:

    void push(int key)
    {

        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(key);
        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }
    void pop(void)
    {
        q1.pop();
    }
    int top(void)
    {
        q1.front();
    }
     bool empty(void)
    {
        return(q1.size()==0);
    }
    int Size(void)
    {
        return q1.size();
    }

};
void print(Stack s)
{
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}
int main()
{
    //Stack<int> s; /*with defining STL(generic) stack Class*/
    //stack<int> s;
    Stack s;
    for(int i=0; i<=5; i++)
    {
        s.push(65+i);
    }

    /*
    Stack s;
    s.push(2);
    s.pop();
    s.pop();
    s.pop();
    s.push(20);
    s.push(200);
    cout<<s.top()<<endl;
    cout<<s.top()<<endl;
    s.push(12);
    cout<<s.top()<<endl;
    */
    print(s);

    return 0;
}

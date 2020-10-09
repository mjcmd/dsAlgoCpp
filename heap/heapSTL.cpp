#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    priority_queue<int> pqueue;   //it is default but actual syntax is priority_queue<int,  vector<int>, less<int>>
    pqueue.push(1);
    pqueue.push(8);
    pqueue.push(3);
    pqueue.push(2);
    //pqueue.push(3);

    cout<<"Initially priority queue, pqueue :";
    while (!pqueue.empty())
    {
        cout<<" "<< pqueue.top();
        pqueue.pop();
    }
    cout<<endl;
    //if pqueue.pop(); is executed here misbehaviour is shown
    // Priority Queue becomes 1
    cout<<"pq.empty(): ";
    if (pqueue.empty())
    {
        cout << "True"<<endl;
    }
    else {
        cout << "False"<<endl;
    }
    // Priority Queue becomes 8, 6, 3, 2, 1

    cout <<"pq.size(): "<< pqueue.size()<<endl;

    // Priority queue top
    cout <<"pq.top(): "<< pqueue.top()<<endl;

    //cout<<pqueue.top();pqueue.pop();cout<<pqueue.top();pqueue.pop();cout<<pqueue.top();
    //pqueue.pop();
    // queue becomes 0

    cout<<"After 2 times pq.pop(): ";
    // Printing content of priority queue
/*
    while (!pqueue.empty())
    {
        cout <<" "<< pqueue.top();
        pqueue.pop();
    } */

    /*

    vector<int> v={2, 5 , 7, 9, 3};
    cout<<"initially vector, v"<<endl;
    for(auto i: v)
        cout<<i<<" ";
    cout<<endl;
    make_heap(v.begin(), v.end());
    cout<<"After make_heap, v"<<endl;
    for(auto i: v)
        cout<<i<<" ";
    cout<<endl;

    v.push_back(100);
    push_heap(v.begin(), v.end());
    cout<<"After push_heap:"<<endl;
    for(auto i: v)
        cout<<i<<" ";
    cout<<endl;

       pop_heap(v.begin(), v.end());
    cout<<"After pop_heap:"<<endl;
    for(auto i: v)
        cout<<i<<" ";
    cout<<endl;

    auto former_top=v.back();
    v.pop_back();
    cout<<"former top element"<<endl;
    cout<<former_top<<endl;
    cout<<"After removing former top element"<<endl;
    for(auto i: v)
        cout<<i<<" ";
    cout<<endl;
    */

    return 0;
}

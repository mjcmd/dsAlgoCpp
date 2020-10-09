#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    node(int key)
    {
        data=key;
        next=NULL;
    }
};


node* merge2SortedLinkedLists(node*& h1, node*& h2);
node* mergeSortedLinkedList2(node*& head1, node*& head2);
void print(node* head);
int main()
{
    node* h1=NULL;
    node* h2=NULL;
    node* t=merge2SortedLinkedLists(h1, h2);

    print(t);
    return 0;
}
void print(node* head)
{
    node* t=head;
    while(t!=NULL)
    {
        cout<<t->data<<"->";
        t=t->next;
    }
}
void insertAtTail(node*& head, int d)
{
    node* temp =head;
    if(head==NULL)
    {
        head=new node(d);
        return;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new node(d);
    return;
}
void buildList1(node*& h)
{
    int d;
    cin>>d;

    while(d!=-1)
    {
        insertAtTail(h, d);
        cin>>d;
    }
}
node* merge2SortedLinkedLists(node*& h1, node*& h2)
{

    buildList1(h1);
    buildList1(h2);
    return mergeSortedLinkedList2(h1, h2);
}
node* mergeSortedLinkedList2(node*& head1, node*& head2)
{
    if(head1==NULL||head2==NULL)
    {
        if(head1==NULL)
        {
            return head2;
        }
        if(head2==NULL)
        {
            return head1;
        }
    }

    if(head1->data<head2->data)
    {
        node* c= mergeSortedLinkedList2(head1->next, head2);
        head1->next=c;
        return head1;
    }
    else
    {
        node* c= mergeSortedLinkedList2(head1, head2->next);
        head2->next=c;
        return head2;
    }
}

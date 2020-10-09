#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node* next;
    node(int k)
    {
        data=k;
        next=NULL;
    }
};
void print(node* head);
void separateOddEven(node*& head);
void insertAtTail(node*& head, int d);
int main()
{
    node* head=NULL;
    /*
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 9);
    insertAtTail(head, 21);
    insertAtTail(head, 9);
    insertAtTail(head, 17); */
    separateOddEven(head);

    /*
    node* t=head->next;
    node* p=head;
    while(t!=NULL)
    {
        if(t->data&1)
        {
            p->next=t->next;
            node* c=t;
            t=t->next;
            c->next=head;
            head=c; continue;
            //break;
        }
        t=t->next;
        p=p->next;
    }
    */
   print(head);

    return 0;
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
void insertAtHead(node*& head, node* t)
{
    //node* t= new node(key);
    t->next=head;
    head=t;
}
void separateOddEven(node*& head)
{
    buildList1(head);

    node* c=head->next;
    node* p=head;
    node* t;

    while(c!=NULL)
    {
        if(c->data&1)
        {
            p->next=c->next;
            t=c;
            c=c->next;
            t->next=NULL;
            insertAtHead(head, t);
            continue;
        }
        p=p->next;
        c=c->next;
    }
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

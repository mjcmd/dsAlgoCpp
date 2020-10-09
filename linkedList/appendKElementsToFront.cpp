#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node* next;

    node(int d)
    {
        data=d;
        next=NULL;
    }
};
void insertAtHead(node*& head, int key)
{
    node* t= new node(key);
    t->next=head;
    head=t;
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
void appendKElementsToFront(node*& head, int k);
node* ptrToKthNodeFromLast(node* head, int k);

int main()
{
    node* head=NULL;
    insertAtHead(head, 1);
    insertAtHead(head, 6);
    insertAtHead(head, 3);
    insertAtHead(head, 9);
    appendKElementsToFront(head, 3);
    //node* t=ptrToKthNodeFromLast(head, 3);

    print(head);
    return 0;
}
node* ptrToKthNodeFromLast(node* head, int k)
{
    node* f=head;
    node* s=head;
    int ju=1;
    while(ju<=k)
    {
        f=f->next;
        ju++;
    }
    while(f->next!=NULL)
    {
        f=f->next;
        s=s->next;
    }

    node* t=s->next;
    s->next=NULL;
    return t;
}

void appendKElementsToFront(node*& head, int k)
{
    node* t=ptrToKthNodeFromLast(head, k);
    node* t2=t;
    while(t2->next!=NULL)
    {
        t2=t2->next;
    }
    t2->next=head;
    head=t;
}

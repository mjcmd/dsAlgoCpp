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

} ;
void print(node* head);
void insertAtHead(node*& head, int d);
node* insertionSort(node*& head);
void insertion(node*& newHead, node* t);

int main()
{
    node* head=NULL;

    insertAtHead(head, 8);
    insertAtHead(head, 6);
    insertAtHead(head, 9);
    insertAtHead(head, 1);
    head=insertionSort(head);
    //node* u= new node(2);
    //cout<<u->data;
    //insertion(head, u);
    print(head);

    return 0;
}
int len(node* head)
{
    node* temp = head;
    int c=0;
    while(temp)
    {
        c++;
        temp=temp->next;
    }
    return c;
}
node* deleteAtHead(node*& head)
{
    if(head==NULL)
        return NULL;
    node* temp=head;
    head=head->next;
    temp->next=NULL;
    return temp;
}
void insertion(node*& newHead, node* t)
{
    node* p=NULL;
    node* c=newHead;

    if(newHead==NULL)
    {
        newHead=t; return;
    }
    while(c->data<t->data&&c->next!=NULL)
    {
        p=c;
        c=c->next;
    }
    if(p==NULL)
    {
        if(c->data<t->data)
        {
            c->next=t; return;
        }
        else
        {
            t->next=c;
            newHead=t;
            return;
        }
    }
    if(c->next==NULL)
    {
        if(c->data<t->data)
        {
            c->next=t;
            return;
        }
        else
        {
            t->next=c;
            p->next=t;
            return;
        }
    }
    t->next=c;
    p->next=t;

    return ;
}
node* insertionSort(node*& head)
{
    node* newHead=NULL;
    node* t=deleteAtHead(head);
    //insertAtHead(newHead, -1);
    /*for(node* t=deleteAtHead(head); t!=NULL; t=deleteAtHead(head))*/while(t!=NULL)//for(int i=1; i<=len(head); i++)
    {
        //cout<<t->data<<endl;;
        insertion(newHead, t);        t=deleteAtHead(head);

    }

    return newHead;

}
    /*
    node* headToSorted=NULL;
    //node* c=;
    insertAtHead(headToSorted, 0);
    insertAtHead(headToSorted, -1);


    for(node* c1=deleteAtHead(head); c1!=NULL; c1=deleteAtHead(head))
    {
        //cout<<c1->data<<endl;
          node* p=headToSorted;
          node* c2=headToSorted->next;
          //cout<<p->data<<c2->data;


        if(headToSorted==NULL)
        {
            headToSorted=c1;
            continue;
        }
        if(headToSorted->next==NULL)
        {
            if(headToSorted->data>c1->data)
            {
                c1->next=headToSorted;
                headToSorted=c1;
            }
            else
            {
                headToSorted->next=c1;
            }
            continue;
        }
         while(c1->data>c2->data&&c2!=NULL)
            {
                p=p->next   ;
                c2=c2->next ;
            }
            c1->next=c2;
            p->next=c1;

    }

    return headToSorted;
    */
void insertAtHead(node*& head, int d)
{

    node* n = new node(d);
    n->next=head;
    head = n;

}
void print(node* head)
{
    node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
}

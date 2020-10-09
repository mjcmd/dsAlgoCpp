
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


void insertAtHead(node*& head, int d);
void insertAtTail(node*& head, int d);
void insertInMiddle(node*& head, int d, int loc);
void deleteAtHead(node*& head);
void deleteAtTail(node*& head);
void deleteInMiddle(node*& head, int n);
void kthNodeFromLast(node* head, int k);
node* midPoint(node* head);
void buildList1(node*& head);
void buildList2(node*& head);
void reverseIterative(node*& head);
void reverseRec1(node*& head, node* p, node* c, node* n);
node* reverseRec2(node*& head);
node* searchRec(node* head, int d);
node* searchIterative(node* head, int k);
node* mergeSortedLinkedList(node*& head1, node*& head2);
node* mergeSortedLinkedList2(node*& head1, node*& head2);
//node* breakAtmid(node* head);
node* mergeSort(node*& head);

void print(node* head);
int len(node* head);
int main()
{
    node* head1 = NULL;
    insertAtHead(head1, 5);
    insertAtHead(head1, 3);
    insertAtHead(head1, 8);
    insertAtHead(head1, 6);
    node* head2 = NULL;
    insertAtHead(head2, 8);
    insertAtHead(head2, 6);
    insertAtHead(head2, 4);
    insertAtHead(head2, 2);
    //insertAtHead(head, 9);
    //insertAtHead(head, 5);

    //insertInMiddle(head, 100, 3);
    insertAtTail(head1, 55);
    //deleteAtHead(head);
    //deleteAtTail(head);
    //deleteInMiddle(head, 3);
    //kthNodeFromLast(head, 2);
    //midPoint(head);
    //node* head=NULL;
    //buildList1(head);
    //buildList2(head);
    //print(head);
    //node* n;
    //reverseRec1(head, NULL, head, n);
    //head = reverseRec2(head);
    //reverseIterative(head);
/*
    node* loc=searchIterative(head, 13);//searchRec2(head, 9);
    if(loc)
        cout<<loc->data<<endl;
    else
        cout<<"not exist";
    cout<<endl;
    */
   /* print(head1);
    cout<<endl;
    print(head2);
    cout<<endl;
    node* head=mergeSortedLinkedList(head1, head2);
    */
    //node* h;
    //node* h2;
   //head1=mergeSort(head1);
   /*
   print(head1);
   cout<<endl;
   h=breakAtmid(head1);

    print(h);
    cout<<endl;
    print(head1);
    cout<<endl;
   h2=breakAtmid(h);
   */
    print(head1);
    //cout<<len(head);

    return 0;
}
void buildList2(node*& head)
{
    node* t;
    int i=1, key, N;
    cin>>N;

    while(i<=N)
    {
        cin>>key;
        insertAtTail(head, key);
        i++;
    }

}
node* midPoint(node* head)
{
    node* s = head;
    node* f = head;

    //int jump=1;
    while(f->next!=NULL&&f->next->next!=NULL)   //runner technique, solve in single pass
    {
       // cout<<s->data;
        f= f->next->next;
        s= s->next;

        //jump++;
    }
    return s;//cout<<s->data<<endl;
}
node* mergeSort(node*& head)
{

    if(head==NULL||head->next==NULL)
    {
        return head;
    }
     node* m=midPoint(head);
    node* l=head;
    node* r=m->next;
    m->next=NULL;

    l=mergeSort(l);
    r=mergeSort(r);

    return mergeSortedLinkedList(l, r);

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
        node* c= mergeSortedLinkedList(head1->next, head2);
        head1->next=c;
        return head1;
    }
    else
    {
        node* c= mergeSortedLinkedList(head1, head2->next);
        head2->next=c;
        return head2;
    }
}
node* mergeSortedLinkedList(node*& head1, node*& head2)
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
        node* c= mergeSortedLinkedList(head1->next, head2);
        head1->next=c;
        return head1;
    }
    else
    {
        node* c= mergeSortedLinkedList(head1, head2->next);
        head2->next=c;
        return head2;
    }
}
node* searchIterative(node* head, int k)
{
    node* temp= head;
    while(temp!=NULL)
    {
        if(temp->data==k)
            return temp;
        temp=temp->next;
    }
    return temp;
}
node* searchRec(node* head, int k)
{
    if(head==NULL)
    {
        return head;
    }
    if(head->data==k)
    {
        return head;
    }
    return searchRec(head->next, k);

}
void reverseRec1(node*& head, node* p, node* c, node* n)
{
    if(c==NULL)
    {
        head=p;
        return;
    }
    n=c->next;
    c->next=p;
    reverseRec1(head, c, n, n);
    return;
}
node* reverseRec2(node*& head)                 //using the recursive property
{
   if(head==NULL||head->next==NULL)
   {
       return head;
   }

   node* smallHead=reverseRec2(head->next);
   node* c=head;
   c->next->next=c;
   c->next=NULL;
   return smallHead;
}
void reverseIterative(node*& head)
{
    node* p=NULL;
    node* c=head;
    node* n;
    while(c!=NULL)
    {
        n=c->next;
        c->next=p;
        p=c;
        c=n;
    }
    head=p;
}
void buildList1(node*& head)
{
    int d;
    cin>>d;

    while(d!=-1)
    {
        insertAtTail(head, d);
        cin>>d;
    }
}

void kthNodeFromLast(node* head, int k)
{

    node* s = head;
    node* f = head;

    int jump=1;
    while(jump<=k-1)     //runner technique, solve in single pass
    {
        f=f->next;
        jump++;
    }

    while(f->next!=NULL)
    {
        f=f->next;
        //f=f->next;
        s=s->next;
    }

    cout<<s->data<<endl;

    /*
    node* t = head;
    int jump=1;
    //cout<<len(head)-k<<endl;
    while(jump<=len(head)-k)
    {
cout<<jump<<" ";
        t=t->next;
        jump++;
        //cout<<jump<<" ";
    }
    */

    //cout<<t->data<<endl;

}
void deleteInMiddle(node*& head, int n)
{
    if(len(head)==0)
    {
        return;
    }
    else if(len(head)<n)
    {
        return;
    }
    else if(n<1)
    {
        return;
    }
    else if(n==1)
    {
        node* temp = head;
        head = head->next;
        delete temp;  return;
    }
    else
    {

        node* temp = head;
        int jump=1;
        while(jump<=n-2)
        {
            temp=temp->next;
            jump++;
        }
        node* t=temp->next;
        temp->next=temp->next->next;
        delete t ;
        return;
    }
    //return;
}
void deleteAtTail(node*& head)
{
    node* temp = head;
    if(head==NULL)
    {
        cout<<"first case ";
        return;

    }

    else if(head->next==NULL)
    {
        cout<<"2 case ";
        head=head->next;
        delete temp;
    }
    else
    {
        cout<<"3 case ";
        //node* temp=head;
        while(temp->next->next!=NULL)
            temp=temp->next;
        node* t=temp->next;
        temp->next=NULL;
        delete t;
    }
}
void deleteAtHead(node*& head)
{
    if(head==NULL)
        return;
    node* temp=head;
    head=head->next;
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
void insertAtHead(node*& head, int d)
{

    node* n = new node(d);
    n->next=head;
    head = n;

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
void insertInMiddle(node*& head, int d, int loc)
{
    node* temp=head;
    if(temp==NULL||loc==0)
    {
        insertAtHead(head, d);
    }
    else if(len(head)<loc)
    {
        insertAtTail(head, d);
    }
    else
    {
        int i=1;
        while(i<=loc-1)
        {
            temp=temp->next;
            i++;
        }
    //cout<<i<<endl;
        node* n=new node(d);
        n->next=temp->next;
        temp->next=n;
    }

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


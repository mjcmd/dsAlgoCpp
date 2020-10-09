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
bool isPalindrome(node*& head);
void buildList1(node*& head);
int main()
{
    node* head=NULL;

    buildList1(head);
    if(isPalindrome(head))
        cout<<"Yes, list is palindrome";
    else
        cout<<" No, list is not palindrome";
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
int kthNodeFromFirst(node*& head, int k)
{
    node* t=head;
    int ju=1;
    while(ju<=k-1)
    {
        t=t->next;
        ju++;
    }
    return t->data;
}
int kthNodeFromLast(node* head, int k)
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

    return s->data;
}
bool isPalindrome(node*& head)
{
    for(int k=1; k<=len(head)/2; k++)
    {
        if(kthNodeFromFirst(head, k)!=kthNodeFromLast(head, k))
        {
            return false;
        }
    }
    return true;
}

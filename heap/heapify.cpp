#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void maxHeapify(vector<int>& A, int n, int i);
void buildHeap(vector<int>&A, int n);
void heapify(vector<int>&A, int n, int i);
void heapSort(vector<int>&A, int n);

int main()
{
    int d;
    vector<int> A;
    cin>>d;
    while(d!=-1)
    {
        A.push_back(d);
        cin>>d;
    }

    //buildHeap(vect, vect.size());
    heapSort(A, A.size());
     cout<<"after applying buildHeap(): ";
        for(int i: A)
            cout<<" "<<i;

        /*
     //indeces->  0   1  2  3  4  5
        int A[6]={10, 8, 1, 4, 2, 3};
        int n=sizeof(A)/sizeof(A[0]);
        int i=2;
        maxHeapify(A, n, i);
        cout<<"after applying maxHeapify(): ";
        for(int i: A)
            cout<<" "<<i;
            */
        return 0;
}
void sortHeap(vector<int>& A, int n)
{
    int hpSize=n;
    while(hpSize>=1)
    {
        swap(A[0], A[hpSize-1]);
        hpSize--;
        maxHeapify(A, hpSize, 0);
    }
}
void heapSort(vector<int>&A, int n)
{
    buildHeap(A, n);
    sortHeap(A, n);
}
void buildHeap(vector<int>&A, int n)
{
    for(int i=n/2-1; i>=0; i--)
    {
        maxHeapify(A, n, i);
    }
}

void maxHeapify(vector<int>& A, int n, int i)
{

     // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2;
    int large = i;
    while(large<=n&&l<=n&&r<=n)
    {
             // right = 2*i + 2

    // If left child is larger than root
    if (l < n && A[l] > A[large])
        large = l;

    // If right child is larger than largest so far
    if (r < n && A[r] > A[large])
        large = r;

    // If largest is not root
    if (large != i)
    {
        swap(A[i], A[large]);
        i = large; // Initialize largest as root
        l = 2 * i + 1; // left = 2*i + 1
        r = 2 * i + 2;
    }
    else
        break;

    }
    /*
    while(2*i+1<=n&&2*i+2<=n&&(A[2*i+1]>A[i]||A[2*i+2]>A[i]))
    {
        if(A[2*i+1]>A[2*i+2])   //comparison of children nodes
            {
                    int tmp=A[i];
                    A[i]=A[2*i+1];
                    A[2*i+1]=tmp;

                    i=2*i+1;
            }
            else
            {
                    int tmp=A[i];
                    A[i]=A[2*i+2];
                    A[2*i+2]=tmp;

                    i=2*i+2;
            }
    }  //end of while loop
    */

}

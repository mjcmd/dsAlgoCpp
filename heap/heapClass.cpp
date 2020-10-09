/*
#A heap is a specialized tree-based data structure which is essentially an ... Order statistics:
The Heap data structure can be used to efficiently find the kth smallest (or largest) element in an array.

#The C++ Standard Library provides the make_heap, push_heap and pop_heap algorithms for heaps (usually implemented as binary heaps),
 which operate on arbitrary random access iterators. It treats the iterators as a reference to an array, and uses the array-to-heap conversion.
 It also provides the container adaptor priority_queue, which wraps these facilities in a container-like class.
 However, there is no standard support for the replace, sift-up/sift-down, or decrease/increase-key operations.
*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class maxHeap
{
    int* arr;
    int sze;
public:
    maxHeap(void)
    {
        int* arr = new int[100];
        sze=0;
    }
    void push(int k)
    {
        arr[sze]=k;

        int i=sze;
       // parIndex=(i-1)/2;

        while(arr[(i-1)/2]<arr[i]&&(i-1)/2>=0)
        {
            int temp=arr[(i-1)/2];
            arr[(i-1)/2]=arr[i];
            arr[i]=temp;
            i=(i-1)/2;
        }

        sze++;

    }
    void pop(void)
    {
        arr[0]=arr[sze-1];
        sze--;

        int i=0;
        //arr[2*i+1]=max(arr[2*i+1], arr[2*i+2]));
        while(2*i+2>=sze&&arr[i]<arr[2*i+1]||arr[i]<arr[2*i+2])
        {
            if(arr[2*i+1]>arr[2*i+2])   //comparison of children nodes
            {
                if(arr[i]<arr[2*i+1])    //comparison of max child with root node
                {
                    int tmp=arr[i];
                    arr[i]=arr[2*i+1];
                    arr[2*i+1]=tmp;

                    i=2*i+1;
                }
            }
            else
            {
                if(arr[i]<arr[2*i+2])
                {
                    int tmp=arr[i];
                    arr[i]=arr[2*i+2];
                    arr[2*i+2]=tmp;

                    i=2*i+2;
                }
            }
        } //while loop end
    }//pop end
    int front(void)
    {
        if(sze)
            return arr[0];
        else
            return -1;
    }
    int Size(void)
    {
        return sze;
    }
    bool isEmpty(void)
    {
        return sze==0;
    }
    void show(void)
    {
        for(int i=0; i<sze; i++)
        {
            cout<<arr[i]<<" ";
        }
    }


     void make_Heap(void)
    {
        int d;
        cin>>d;
        while(d!=-1)
        {
            push(d);
            cin>>d;
        }
    }
};

int main()
{
    maxHeap h;
    h.make_Heap();
/*
    h.push(3);
    h.push(6);
    h.push(9);
    h.push(1000); */
    h.show();
    cout<<endl;
    h.pop();
    h.show();
    cout<<endl;
    h.pop();
    h.show();


    cout<<endl;
    cout<<h.front();


    return 0;
}

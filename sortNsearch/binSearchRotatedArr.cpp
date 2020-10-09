/* PS:
Rahul had a sorted array of numbers from which
he had to find a given number quickly.
His friend by mistake rotated the array.
Now Rahul doesn't have time to sort the elements again.
Help him to quickly find the given number from the rotated array.
*/

#include<iostream>

using namespace std;

int location;
int binSearch(int target, int* a,int l,int r);
int pivotSortedRotatedArr(int* a, int N);
void binSearchRotatedArr(void);


int main()
{
    binSearchRotatedArr();
return 0;
}

int binSearch(int target, int* a,int l,int r)
{
    int mid;
    while(l<=r)
    {
        mid = (l+r)/2;
        if(target==a[mid])
            {
                location = mid;
                return true;
            }
        else if(target<a[mid])
            r=mid-1;
        else
            l=mid+1;
    }
    return false;
}
int pivotSortedRotatedArr(int* a, int N)
{
    int j;
    for(j= 0; j<N-1; j++)
    {
        if(a[j]>a[j+1])
            return j;
    }
}
void binSearchRotatedArr(void)
{
    int N,target;
    int a[N];

    cin>>target;
    for(int i =0; i<N; i++)
        cin>>a[i];

    int pivot;
    int j;
    for(j= 0; j<N-1; j++)
    {
        if(a[j]>a[j+1])
            pivot =j;
    }
    if(binSearch(target,a,0,pivot))
        cout<<location;
    else if(binSearch(target,a,pivot+1, N-1))
        cout<<location;
    else
        cout<<"Not Found!";

}

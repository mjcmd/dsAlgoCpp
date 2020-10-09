/*PS : PIVOT OF SORTED AND ROTATED ARRAY
You are given a sorted but rotated array.
You need to fine the index of the pivot element of the array
where pivot is that element in the array which is greater than its next element
and divides the array into two monotonically increasing halves.
*/

#include<iostream>

using namespace std;

 void pivotSortedRotatedArr(void);
int main()
{
    pivotSortedRotatedArr();
return 0;
}
void pivotSortedRotatedArr(void)
{
    int N;
    cin>>N;
    int a[N];
    for(int i=0; i<N; i++)
    cin>>a[i];
    int j;
    for(j= 0; j<N; j++)
    {
        if(a[j]>a[j+1])
            break;
    }
    cout<<"pivot index "<<j<<endl;
}

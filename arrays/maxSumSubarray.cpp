#include<iostream>
#include<climits>
using namespace std;
void maxSumSubarray(int* arr,int N);
void maxcirSumSubarray(int* arr,int N);
int main()
{
    int a[10]={2,3,-6,-7,4,5};
    maxcirSumSubarray(a,6);
    //maxSumSubarray(a,10);
return 0;
}
void maxcirSumSubarray(int* arr,int N)
{
    int s=0;
    int maX=INT_MIN;
    int beg,en;
    for(int i=0; i<=N-1; i++)
    {
        s=0;
        int k=i;
        for(int j=1; j<=N-1; j++,k=(k+1)%N)
        {
            s = s+arr[k];
            if(s>maX)
            {
                maX=s;
                beg=i; en=k;
            }

        }
    }
    cout<<"maximum subarray sum and the subarray are "<<maX<<" "<<"["<<beg<<"]"<<"["<<en <<"]"<<endl;
}
void maxSumSubarray(int* arr,int N)
{
    int s=0;
    int maX=INT_MIN;
    int beg,en;
    for(int i=0; i<=N-1; i++)
    {
        s=0;
        for(int j=i; j<=N-1; j++)
        {
            s = s+arr[j];
            if(s>maX)
            {
                maX=s;
                beg=i; en=j;
            }

        }
    }
    cout<<"maximum subarray sum and the subarray are "<<maX<<" "<<"["<<beg<<"]"<<"["<<en <<"]"<<endl;
}

#include<iostream>

using namespace std;
void maxSumSubarray(int* arr,int N);
bool isBitonic(int* a,int i,int j);
int main()
{
    int a[6]={12, 4, 78, 90, 45, 23};
    maxSumSubarray(a,6);
return 0;
}
bool isBitonic(int* a,int i,int j)
{
    int k=0;
    while(i<=j)
    {
        if(a[i]>a[i+1])
            break;
        i++;
    }
    if(i!=j)
        k=1;
    while(i<=j)
    {
        if(a[i]<a[i+1])
            break;
        i++;
    }
    if(i!=j)
        k=2;

        return (k==1)?1:0;
}
void maxSumSubarray(int* arr,int N)
{
    int maxlen=INT_MIN;
    int beg,en;

    for(int i=0; i<=N-1; i++)
    {

        for(int j=i; j<=N-1; j++)
        {

            if(isBitonic(arr,i,j))
            {
               int bitonicSubarrLen=j-i+1;
                if(bitonicSubarrLen>maxlen)
                {
                    beg=i; en=j;
                   maxlen = bitonicSubarrLen;
                }

            }

        }
    }
    cout<<"maximum bitonic subarray length and the subarray are "<<maxlen<<" "<<"["<<beg<<"]"<<"["<<en <<"]"<<endl;
}

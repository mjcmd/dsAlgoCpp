#include<iostream>

using namespace std;
void selectionsort(void);
int main()
{
    //selectionsort();
return 0;
}
int minindex(int i, int n, int* arr)
{
     int minn=INT_MAX ;//int assumedmin=i;
        int minnindex;
    for(int j =i; j<=n; j++)
        {
            if(minn>arr[j])//arr[assumedmin]
            {
                minn=arr[j];
                minnindex=j;
                /*int t = arr[assumedmin];
                arr[assumedmin]=arr[j];
                arr[j]=t;*/
            }
        }
        return minnindex;
}
void swap(int i, int minnindex, int* arr)
{
                int t = arr[i];
                arr[i]=arr[minnindex];
                arr[minnindex]=t;

}
void selectionsort(void)
{
    int N;
    cin>>N;
    //int a[N];
    int arr[N];
    for(int i =0; i<N; i++)
        cin>>arr[i];

    for(int i = 0; i<=N-2; i++)
    {

        int minnindex=minindex(i, N-1, arr);
        swap(i,minnindex, arr );

    }
    for(int i =0; i<N; i++)
        cout<<arr[i];
}-


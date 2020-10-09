#include<iostream>

using namespace std;
void bubblesort(void);
int main()
{
    bubblesort();
return 0;
}
void bubblesort(void)
{
    int N;
    cin>>N;
    int arr[N];
    for(int i =0; i<N; i++)
        cin>>arr[i];

    for(int i = 0; i<=N-2; i++)
    {
        for(int j =N-1; j>=i+1; j--)
        {
            if(arr[j]<arr[j-1])
            {
                int t = arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=t;
            }
        }
    }
    for(int i =0; i<N; i++)
        cout<<arr[i];
}

#include<iostream>

using namespace std;

void insertionsort(void);
int main()
{
    insertionsort();
  return 0;
}
void insertionsort(void)
{
    int N;
    cin>>N;
    int arr[N];
    for(int i =0; i<N; i++)
        cin>>arr[i];

    for(int i = 0; i<=N-2; i++)
    {
        int f=i+1;
        for(int j=f; j>=1; j--)
        {
            if(arr[j-1]>arr[j])
            {
                int t = arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=t;
                f=f-1;
            }
            else
                break;
        }
    }
    for(int i =0; i<N; i++)
        cout<<arr[i];
}

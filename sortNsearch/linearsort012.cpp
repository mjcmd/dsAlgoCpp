// PS: You will be given an array containing only 0s, 1s and 2s. you have sort the array in linear time that is O(N) where N is the size of the array.

#include<iostream>

using namespace std;
void linearsort(void);
int main()
{
    linearsort();
return 0;
}
void linearsort(void)
{
    int N;
    cin>>N;
    int arr[N];
    for(int i =0; i<N; i++)
        cin>>arr[i];

int a[N];
int s=0,l=N-1;
    for(int j = 0; j<N-1; j++)
    {


            switch(arr[j+1])
            {
            case 0:
            {
                a[s]=a[j+1];
                s++;
            }

            case 2:
            {
                a[l]=a[j+1];
                l--;
            }
            }
    }
     for(int j = 0; j<N-1; j++)
    {
       if(arr[j+1]==1)
       {
             a[s]=a[j+1];
                s++;
       }

    }
    for(int i =0; i<N; i++)
        cout<<a[i];
}

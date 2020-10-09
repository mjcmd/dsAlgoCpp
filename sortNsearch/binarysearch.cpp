#include<iostream>

using namespace std;
int binarysearch(void);

int main()
{
    cout<<binarysearch();

return 0;
}
int binarysearch(void)
{
     int N;
    cin>>N;
    int a[N];
    for(int i =0; i<N; i++)
        cin>>a[i];
    int x;
    cin>>x;
     int l=0,r=N-1,mid;
    for(; l<=r; )
    {
        mid=(l+r)/2;
        if(x==a[mid])
        {
            return mid;
        }
        else if(x>a[mid])
        {
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    if(l>r)
    cout<<-1;
}

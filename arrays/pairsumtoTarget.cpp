
// problem statement:ARRAYS-TARGET SUM PAIRS
#include<iostream>

using namespace std;
void pairtsumtoTarget(int N);
void triplettsumtoTarget(int N);
int main()
{int x;
    cin>>x;
    triplettsumtoTarget(x);
//pairtsumtoTarget(x);
return 0;
}
void triplettsumtoTarget(int N)
{
    int a[N], Target;
    for(int i=0; i<N; i++)
    {
        cin>>a[i];
    }
    cin>>Target;
    for(int i=0; i<N; i++)
    {
        for(int j=i+1; j<N; j++)
        {
            for(int k=j+1; k<N; k++)
            {
               if(a[i]+a[j]+a[k]==Target)
               cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<endl;
            }
        }

    }

}
void pairtsumtoTarget(int N)
{
    int a[N], Target;
    for(int i=0; i<N; i++)
    {
        cin>>a[i];
    }
    cin>>Target;
    for(int i=0; i<N; i++)
    {
        for(int j=i; j<N; j++)
        {
           if(a[i]+a[j]==Target)
            cout<<a[i]<<" "<<a[j]<<endl;
        }

    }

}

/* problem statement:
Take N as input. For a value of N=7, we wish to draw the following pattern :

                            1
                        2 1   1 2
                    3 2 1       1 2 3
                4 3 2 1           1 2 3 4
                    3 2 1       1 2 3
                        2 1   1 2
                            1
                            */
#include<iostream>

using namespace std;
void doublSidedArrow(int N);
int main()
{
doublSidedArrow(7);
return(0);
}
void doublSidedArrow(int N)
{
    for(int i = 1, z = 6; i<=N-3; ++i, z = z-2)
    {
        if(i==1)
        {
            cout<<"      1      "<<"\n";

            continue;
        }
        int midspc = 13-2*z-2*i;
        int j = 1;
        while(j<=z)
        {
            cout<<" "; j++;
        }
         int k = i;
        while(k>=1)
        {
            cout<<k; k--;
        }
        int l = 1;
        while(l<=midspc)
        {
            cout<<" "; l++;
        }
        int m = 1;
        while(m<=i)
        {
            cout<<m; m++;
        }
        j = 1;
        while(j<=z)
        {
            cout<<" "; j++;
        }
        cout<<"\n";
    }
    for(int i = N-4, z = 2; i>=1; i--,z=z+2)
    {
         if(i==1)
        {
            cout<<"      1      ";
            continue;
        }
        int midspc = 13-2*z-2*i;
        int j = 1;
        while(j<=z)
        {
            cout<<" "; j++;
        }
        int k = i;
        while(k>=1)
        {
            cout<<k; k--;
        }
        int l = 1;
        while(l<=midspc)
        {
            cout<<" "; l++;
        }
        int m = 1;
        while(m<=i)
        {
            cout<<m; m++;
        }
        j = 1;
        while(j<=z)
        {
            cout<<" "; j++;
        }
        cout<<"\n";
    }
}

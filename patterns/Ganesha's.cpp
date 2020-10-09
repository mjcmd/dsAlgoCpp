/* problem statement:
Take as input N, an odd number (>=5) . Print the following pattern as given below for N = 7.

*  ****
*  *
*  *
*******
   *  *
   *  *
****  *
*/
#include<iostream>

using namespace std;

void ganesha(int N);
int main()
{
ganesha(19);
return 0;
}
void ganesha(int N)
{
    int ep = (N-3)/2;

    cout<<"*";
    int i=1;
    while(i<=ep)
    {
        cout<<" "; i++;
    }
    cout<<"*";
    int j = 1;
    while(j<=ep)
    {
        cout<<"*"; j++;
    }
    cout<<"*";
    cout<<"\n";

    for(int i =1; i<=ep; i++)
    {
        cout<<"*";
        int j = 1;
        while(j<=ep)
        {
            cout<<" "; j++;
        }
        cout<<"*";
        int k = 1;
        while(k<=ep)
        {
          cout<<" "; k++;
        }
        cout<<" ";
        cout<<"\n";
    }
    j = 1;
    while(j<=N)
    {
        cout<<"*"; j++;
    }
    cout<<"\n";
        for(int i =1; i<=ep; i++)
    {
        cout<<" ";
        int j = 1;
        while(j<=ep)
        {
            cout<<" "; j++;
        }
        cout<<"*";
        int k = 1;
        while(k<=ep)
        {
          cout<<" "; k++;
        }
        cout<<"*";
        cout<<"\n";
    }
     cout<<"*";
    i=1;
    while(i<=ep)
    {
        cout<<"*"; i++;
    }
    cout<<"*";
    j = 1;
    while(j<=ep)
    {
        cout<<" "; j++;
    }
    cout<<"*";
    cout<<"\n";

}

#include<iostream>
#define INF 1000
using namespace std;
int rainharvest(void);
int helpinghand(int arr2[]);
int main()
{
cout<<rainharvest();
return 0;
}
int rainharvest(void)
{
    int arrElevation[10] = {0,7,1,3,0,1,2,1,2,1};
    int arr1[10], arr2[10];
    int posit;
     for(int j =0; j<=9; j++)
        arr2[j]=arrElevation[j];
    for(int i =0 ; i<INF; i++)
    {
        for(int j =0; j<=9; j++)
        arr1[j]=arr2[j];

        for(int j =0; j<=9; j++)
        arr2[j]=arr2[j]-1;
        posit = helpinghand(arr2);
        if(posit<=1)
            break;
    }
    int firstpositindex;

    for(int j =0; j<10; j++)
        {
            if(arr1[j]>=0)
            {
                firstpositindex=j;
                break;

            }
        }
        int sum =0 ;
        int c=1 ;
        for(int i=firstpositindex+1; i<=9; i++)
        {

            if(arr1[i]<0)
            sum = sum + arr1[i];
            else
            {
                c=c+1;
                if(c==posit)
                break;

            }
        }
    return sum;
}
int helpinghand(int arr2[])
{
    int x = 0;
    for(int j =0; j<=9; j++)
        if(arr2[j]>=0)
            x=x+1;
    return x;
}

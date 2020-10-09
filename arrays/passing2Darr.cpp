#include<iostream>

using namespace std;

/*
const int r=2, c=2; //const is mandatory
void fun(int arr[r][c])
{
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
           {
                arr[i][j]=0;
           }
    }
}
*/
/*
const int c=2; //const is mandatory
void fun(int arr[][c], int r)
{
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
           {
                arr[i][j]=0;
           }
           cout<<endl;
    }
}
*/

void fun(int* arr, int r, int c)
{
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
           {
                *(arr+i*c+j)=0;
           }
           cout<<endl;
    }
}
int main()
{
    int arr[2][2]={ 2, 4,
                    6, 9
    };

    //fun(arr, r, c);
    fun((int*)arr, 2, 2);
    /*

    */
    //fun(arr);
    int r=2, c=2;
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
           {
                cout<<arr[i][j];
           }
           cout<<endl;
    }
    return 0;
}

#include<iostream>

/*  problem statement:
ARRAYS-MAX VALUE IN ARRAY
Take as input N, the size of array. Take N more inputs and store that in an array. Write a function which returns the maximum value in the array. Print the value returned.

1.It reads a number N.

2.Take Another N numbers as input and store them in an Array.

3.calculate the max value in the array and return that value.
*/
using namespace std;
int arrMax(int N);
int main()
{int x;
    cin>>x;
cout<< arrMax(x);
return 0;
}
int arrMax(int N)
{
    int arr[N];
    for(int i=0; i<N; i++)
    cin>>arr[i];
    int j=0;int c;
    while(j<N-1)
    {

        if(arr[j]<arr[j+1])
            c=arr[j+1];
        else
            c=arr[j];
        j++;
    }
    return c;
}

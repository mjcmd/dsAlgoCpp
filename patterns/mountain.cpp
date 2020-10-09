/*problem statement:
Take N (number of rows), print the following pattern (for N = 4).

                       1           1
                       1 2       2 1
                       1 2 3   3 2 1
                       1 2 3 4 3 2 1
*/

#include<iostream>

using namespace std;


void mountain(int N);

int main()
{

  mountain(4);

return 0;
}


void mountain(int N)
{
	for(int i =1; i<=N-1; ++i)
	{    int j=1;
		while(j<=i)
		{
			cout<<j;
			j++;
		}
		for(int k=1; k<=2*N-1-2*i; k++)
		cout<<" ";
		j=0;
		while(j<=i-1)
		{
			cout<<i-j;
			j++;
		}
		cout<<"\n";
	}

	for(int i=1;i<=N;i++)
	cout<<i;


	for(int j=1;j<N;j++)
	cout<<N-j;


}

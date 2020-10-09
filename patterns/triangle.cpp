/*Problem Statement:
Take N (number of rows), print the following pattern (for N = 4).

                       1
                     2 3 2
                   3 4 5 4 3
                 4 5 6 7 6 5 4
*/
#include<iostream>

using namespace std;


void triangle(int N);
int main()
{
  triangle(4);

return 0;
}
void triangle(int N)
{
	int l = 2*N-1;
	int h = N;
	for(int i = 1; i<=h; ++i)
	{
		int spc = l-2*i+1;
		int j=1;
		while(j<=spc/2)
		{
			cout<<" ";
		}
		int k=1;
		while(k<=i)
		{
			cout<<k;
			++k;
		}
		int m =i-1;
		while(m >=1)
		{
			cout<<m;
			--m;
		}
			j=1;
		while(j<=spc/2)
		{
			cout<<" ";
		}
			cout<<"\n";
	}
}

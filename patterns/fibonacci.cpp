/* problem statement:
Take N (number of rows), print the following pattern (for N = 4)
0
1 1
2 3 5
8 13 21 34
*/

#include<iostream>

using namespace std;

void fibonacci(int N);

int main()
{
  fibonacci(10);
return 0;
}

void fibonacci(int N)
{
	int a = 1, b = 1, c = 1,d;
	if(N==1)
	{
		cout<<a;
		return;
	}
	else if(N==2)
	{
		cout<<a<<endl;
		cout<<b<<"\t"<<c<<endl;
		return;
	}

	else
	{
		cout<<a<<endl;
		cout<<b<<c<<endl;
		for(int i = 3; i<=N; ++i)
		{
			int j=1;
			cout<<i-1;
			while(j<=i-2)
			{

				cout<<0;
				j++;
			}
			cout<<i-1;
			cout<<"\n";
		}
		return;
	}
}

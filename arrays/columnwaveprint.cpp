#include<iostream>

using namespace std;
void colWavePrint(int M,int N);
int main()
{int N,M;
    cin>>M>>N;
colWavePrint(M,N);
return 0;
}
void colWavePrint(int M,int N)
{
    int mat[M][N];
    for(int i=0; i<M; i++)
    {
        for(int j=0; j<N; j++)
            cin>>mat[i][j];
    }
     for(int i=0; i<N; i++)
    {
        if(i%2==0)
            for(int j=0; j<M; j++)
            cout<<mat[j][i]<<" ";
        else
            for(int j=M-1; j>=0; j--)
            cout<<mat[i][j]<<" ";
    }
    cout<<"END";
}

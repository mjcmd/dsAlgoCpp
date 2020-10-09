#include<bits/stdc++.h>
#define M 4
using namespace std;

bool Nqueen(int board[M][M], int i, int j);
void printSolution(int board[M][M]);
int main()
{
    int board[M][M]={0};
    int i=0, j=0;
    if(Nqueen(board, i, j))
        printSolution(board);
    else
        cout<<"Arrangement does Not exist";
    return 0;
}
void printSolution(int board[M][M])
{
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++)
            cout<<board[i][j];
        cout<<endl;
    }
}
bool isSafe(int board[M][M], int r, int c)
{
            for (int i = c; i >= 0; i--)
                if(board[r][i])
                    return false;

            for(int i=r,j=c; i<M&&j>=0; i++, j--)
                if(board[i][j]==1)
                    return false;

            for(int i=r, j=c; i>=0&&j>=0; i--, j--)
                if(board[i][j]==1)
                    return false;

    return true;
}
bool Nqueen(int board[M][M], int i, int j)
{

    if(j==M)
        return true;
    for(int i=0; i<M; i++)
    {
        if(isSafe(board, i, j))
        {
            board[i][j]=1;
            if(Nqueen(board, i, j+1))
                return true;

            board[i][j]=0;
        }
    }
    return false;
}

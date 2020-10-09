#include<bits/stdc++.h>

using namespace std;

bool ratInMaze2dir(int* mat, int* sol, int i, int j, int r, int c);
void printSolution(int* sol, int r, int c) ;
int main()
{
    int sol[4][4]={0};

    int mat[4][4]={ {1, 0, 0, 0},
                    {1, 1, 1, 1},
                    {0, 1, 0, 1},
                    {1, 1, 1, 1}
    };

    int i=0, j=0, r=4, c=4;

    if(ratInMaze2dir((int*)mat, (int*)sol, i, j, r, c))
        printSolution((int*)sol, r, c);
    else
        cout<<"path does Not exist";

    return 0;
}
void printSolution(int* sol, int r, int c)
{
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            cout<<*(sol+i*c+j);
        cout<<endl;
    }
}
/* for(int i=0; i<r-1; i++)
       {
           cout<<'\n';
            for(int j=0; j<c-1; j++)
                cout<<*(sol+i*c+j);
       }
       return;
       */
bool isSafe(int* mat, int i, int j, int r, int c)
{
    if(*(mat+i*c+j)==1&&i>=0&&j>=0&&i<r&&j<c)
        return true;

        return false;
}
bool ratInMaze2dir(int* mat, int* sol, int i, int j, int r, int c)
{

    if(i==r-1&&j==c-1&&(*(mat+i*c+j))==1)
   {
        *(sol+i*c+j)=1;
        return true;
   }
   if(isSafe((int*)mat, i, j, r, c))
    {
        *(sol+i*c+j)=1;

        if(ratInMaze2dir((int*)mat, (int*)sol, i+1, j, r, c))
            return true;

        if(ratInMaze2dir((int*)mat, (int*)sol, i, j+1, r, c))
            return true;


        *(sol+i*c+j)=0;
        return false;
    }
   return false;
}

#include<iostream>
#include<bits/stdc++.h>
#define M 8
#define N 8
using namespace std;

void print(int screen[M][N])
{
    for(int i=0; i<M; i++)
    {
        cout<<endl;
        for(int j=0; j<N; j++)
            {
                cout<<screen[i][j]<<" ";
            }
    }
}

void colorFill(int screen[M][N], int i, int j, int oldC, int newC)
{
    if(i<0||i>M||j<0||j>N)
        return;
    if(screen[i][j]!=oldC)
        return;
    if(screen[i][j]==newC)
        return;
    screen[i][j]=newC;
    colorFill(screen, i-1, j, oldC, newC);
    colorFill(screen, i+1, j, oldC, newC);
    colorFill(screen, i, j-1, oldC, newC);
    colorFill(screen, i, j+1, oldC, newC);

    colorFill(screen, i-1, j-1, oldC, newC);
    colorFill(screen, i+1, j+1, oldC, newC);
    colorFill(screen, i+1, j-1, oldC, newC);
    colorFill(screen, i-1, j+1, oldC, newC);


}

int main()
{
    int screen[M][N] = {{1, 1, 1, 1, 1, 1, 1, 1},
                      {1, 1, 1, 1, 1, 1, 0, 0},
                      {1, 0, 0, 1, 1, 0, 1, 1},
                      {1, 2, 2, 2, 2, 0, 1, 0},
                      {1, 1, 1, 2, 2, 0, 1, 0},
                      {1, 1, 1, 2, 2, 2, 2, 0},
                      {1, 1, 1, 1, 1, 2, 1, 1},
                      {1, 1, 1, 1, 1, 2, 2, 1},
                      };
    cout<<"old screen..."<<endl;
    print(screen);
    cout<<endl;
    int oldC=2, newC=0;
    colorFill(screen, 3, 4, oldC, newC);
    cout<<"new screen..."<<endl;
    print(screen);
    return 0;
}

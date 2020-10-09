
#include<bits/stdc++.h>
#define N 8
using namespace std;

int x[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int y[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

bool nightTour(int sol[N][N], int i, int j, int mvNo);
void print(int sol[N][N]);


bool insideboard(int sol[N][N], int i, int j)
{
    if((i>=0&&i<N)&&(j>=0&&j<N))
        return true;
    return false;
}
bool emptyLocation(int sol[N][N], int i, int j)
{
    return sol[i][j]==0;
}

bool isValidStep(int sol[N][N], int i, int j)
{
    return insideboard(sol, i, j)&&emptyLocation(sol, i, j);
}
int main()
{
    int sol[N][N]={0};
    sol[0][0]=1;
    int i, j, mvNo;
    if(nightTour(sol, i=0, j=0, mvNo=2))
        cout<<"solutioN exist!";
    else
        cout<<"No solution";
    //cout<<insideboard(sol, 8, 7);
    //cout<<emptyLocation(sol, 0, 6);
    //cout<<isValidStep(sol, 2, -1);
    //print(sol);
    return 0;
}
void print(int sol[N][N])
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cout<<sol[i][j]<<" ";
        }
        cout<<endl;

    }
    //cout<<endl;
}

bool nightTour(int sol[N][N], int i, int j, int mvNo)
{

    //cout<<mvNo<<endl;
    if(mvNo==65)
    {
        print(sol);
        //cout<<endl;
        return true;
    }


        for(int s = 0; s<8; s++)
        {
            //cout<<s;
            //i=i+x[s];
            //j=j+y[s];
            if(isValidStep(sol, i+x[s], j+y[s]))
            {

                sol[i+x[s]][j+y[s]]=mvNo;
                //cout<<"s";
                if(nightTour(sol, i+x[s], j+y[s], mvNo+1))
                    return true;

                sol[i+x[s]][j+y[s]]=0;
            }

        }

    return false;
}

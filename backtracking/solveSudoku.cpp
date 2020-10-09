#include<bits/stdc++.h>
#include<iostream>

using namespace std;

vector<vector<int>> grid;
bool isSafe(vector<vector<int>> grid, int d, int r, int c);
bool solveSudoku(vector<vector<int>>* grid);
void print( vector<vector<int>> grid);

int main()
{
    int i;
vector<vector<int>> grid = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                             { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                             { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                             { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                             { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                             { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                             { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                             { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                             { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };
    //cout<<inSubgrid(grid, 9, 4, 4);
    //cout<<inCol(grid, 1, 1);
    //cout<<inRow(grid, 1, 0);
    //cout<<unassigned(grid, 0, 1);

    if(solveSudoku(&grid))
        cout<<"Solution obtained!";
        //cout<<isSafe(grid, 1, 0, 1);
    return 0;
}
void print( vector<vector<int>> grid)
{
    int i, j;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++)
            cout<<grid[i][j];
        cout<<endl;
    }
}


bool unassigned(vector<vector<int>> grid, int r, int c)
{
    //cout<<grid[r][c];
    if(grid[r][c]==0)
        return true;
    else
        return false;
}
bool inCol(vector<vector<int>> grid, int d, int c)
{
    //check in column
    for(int i=0; i<9; i++)
    {
        if(grid[i][c]==d)
        {
            return true;
        }
    }
    return false;
}
bool inRow(vector<vector<int>> grid, int d, int r)
{
  for(int j=0; j<9; j++)
    {
        if(grid[r][j]==d)
        {
            return true;
        }
    }
    return false;
}
bool inSubgrid(vector<vector<int>> grid, int d, int r, int c)
{
    int sr=r-r%3, sc=c-c%3;
    //cout<<i<<" "<<j<<endl;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(grid[i+sr][j+sc]==d)
                return true;
        }
    }
    return false;
}

bool isSafe(vector<vector<int>> grid, int d, int r, int c)
{
    return !inCol(grid, d, c)&&!inRow(grid, d, r)&&!inSubgrid(grid, d, r, c)&&unassigned(grid, r, c);
}
bool completeAssigned(vector<vector<int>> grid)
{
    int row, col;
    for (row = 0; row < 9; row++)
        for (col = 0; col < 9; col++)
            if (grid[row][col] == 0)
                return false;
    return true;
}
void FindUnassignedLocation(vector<vector<int>> grid,
                            int& r, int& c)
{
    for (r = 0; r < 9; r++)
        for (c = 0; c < 9; c++)
            if (grid[r][c] == 0)
                return ;
    return ;
}
bool solveSudoku(vector<vector<int>>* grid)
{
    vector<vector<int>> g=*grid;
    //cout<<i<<endl;
    if(completeAssigned(g))
    {
        print(g);
        return true;
    }
    //finding the coordinates of ith location
   /* int c, r;
    r = (i%9==0)? (i/9-1) :i/9;
    c = (i%9==0)? 8       :(i%9-1);
    */
    int r, c;
    FindUnassignedLocation(g, r, c);
    //cout<<r<<" "<<c<<endl;
    //if(unassigned(grid, r, c))
    {
        for(int d=1; d<=9; d++)
        {

               if(isSafe(g, d, r, c))
                { //cout<<d;
                    g[r][c]=d;
                    //print(g);cout<<endl;
                    if(solveSudoku(&g))
                        return true;

                    g[r][c]=0;
                }
        }

        return false;
    }
    //return true;


}

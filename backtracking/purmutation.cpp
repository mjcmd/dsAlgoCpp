#include<bits/stdc++.h>
#include<iostream>

using namespace std;


void permutation(vector<int>arr, vector<int>sol, int i);
int main()
{
    vector<int> arr={'s', 'u', 'n', 'i', 'l'}, sol;
    int i=0;
    permutation(arr, sol, i);
    return 0;
}
void print(vector<int> sol)
{
    for(int k=0; k<sol.size(); k++)
        cout<<sol[k];
    cout<<endl;
}
bool isAgain(vector<int>arr,vector<int> sol, int k)
{
    for(int i=0; i<sol.size(); i++)
        {
            if(arr[k]==sol[i])
                return true;

        }
    return false;
}
void permutation(vector<int>arr,vector<int > sol, int i)
{
    if(i==arr.size())
    {
        print(sol);
        return;
    }
    for(int k=0; k<arr.size(); k++)
    {
        if(!isAgain(arr, sol, k))
        {
            sol.push_back(arr[k]);
            permutation(arr, sol, i+1);

            sol.pop_back();
        }

    }
    return;
}

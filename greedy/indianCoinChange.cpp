#include<iostream>
#include<bits/stdc++.h>

using namespace std;
void indianCoinChange(vector<int> indian_deno, int x, vector<int>& sol_freq);


int main()
{
    vector<int> indian_deno={2000, 500, 200, 100, 50, 20, 10, 5, 2, 1}, sol_freq(10, 0);
    int x=1;
    indianCoinChange(indian_deno, x, sol_freq);//find minimum number of denominations for a given amount x

    for(int i=0; i<sol_freq.size(); i++)
    {
        cout<<indian_deno[i]<<" : "<<sol_freq[i]<<endl;
    }

    return 0;
}
int find_deno(vector<int> indian_deno, int x)
{
    if(x>indian_deno[0])
        return 0;
        int i=0;
    while(x<indian_deno[i])
        {
            i++;
        }
        return i;
}

void indianCoinChange(vector<int> indian_deno, int x, vector<int>& sol_freq)
{
    while(x>0)
    {
        int deno_index=find_deno(indian_deno, x);
        sol_freq[deno_index]++;
        x-=indian_deno[deno_index];
    }
}

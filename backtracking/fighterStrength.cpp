#include<bits/stdc++.h>
using namespace std;

void strogestFighter(vector<int> fighterStrength, int k, vector<int>& sol);


int main()
{
    vector<int> fighterStrength = {1, 3, 2, 4, 5, 9}, sol;
    int k=3;
    strogestFighter(fighterStrength, k, sol);

    return 0;
}
void strogestFighter(vector<int> fighterStrength, int k, vector<int>& sol)
{
    queue<int> q;

    int i=0, mx=-1;
    while(i<=k-2)     // initialisation of queue
    {
        q.push(fighterStrength[i]);
        i++;
    }
    while(i<fighterStrength.size())
    {
        q.push(fighterStrength[i]);
        int j=1;
        while(j<=k)
        {
            if(q.front()>mx)
                mx=q.front();
            int f=q.front();
            q.push(f);
            q.pop();
            j++;
        }
        sol.push_back(mx);


        q.pop();

        i++;
    }

    for(int i=0; i<sol.size(); i++)
        cout<<sol[i]<<" " ;

}

#include<bits/stdc++.h>
using namespace std;

void nxtGreater(void);

int main()
{
    nxtGreater();


    return 0;
}
void nxtGreater(void)
{
    stack<int> s;
    vector<int> v={1, 2, 3, 6, 90, 4};
    vector<int> sol;

    for(int curr=0; curr<v.size(); curr++)
    {
        int i=curr+1;
        while(i!=curr)
        {
            if(v[i]>v[curr])   //push all elements greater than current element into the stack
            {
                s.push(i);
            }
            i=(i+1)%v.size();
        }
        if(s.empty())          //if there is no greater than current element then push -1
        {
            sol.push_back(-1);
            continue;
        }
        int ns=INT_MAX;
        while(!s.empty())
        {
            if(v[s.top()]<ns)        //find minimum from stack which is next greater than current element
            {
                ns=v[s.top()];
            }
            s.pop();
        }

        sol.push_back(ns);

    }
        for(int i=0; i<sol.size(); i++)
            cout<<sol[i]<<" ";
}


#include<bits/stdc++.h>
using namespace std;

int mxArea(vector<int> histo);


int main()
{
    vector<int> histo = {6, 2, 5, 4, 5, 1, 6};
    cout<<mxArea(histo);
    return 0;
}
int calArea(int tp, int i, stack<int> s, vector<int> histo)
{
    if(s.empty())
    {
        return histo[tp]*(i);
    }
    else
    {
        return histo[tp]*(i-s.top()-1);
    }
}

int mxArea(vector<int> histo)
{
    int mxAre=INT_MIN, area;
    stack<int> s;

    for(int i=0; i<=histo.size(); i++)
    {
        if((s.empty()||histo[i]>histo[s.top()])&&i!=histo.size())
        {
            s.push(i);
        }
        else
        {
            int tp;
            while(!s.empty()&&histo[s.top()]>histo[i])
            {
                tp=s.top();
                s.pop();
                area=calArea(tp, i, s, histo);
                if(mxAre<area)
                {
                    mxAre=area;
                }

            }
            s.push(i);
        }
    }

    return mxAre;
}

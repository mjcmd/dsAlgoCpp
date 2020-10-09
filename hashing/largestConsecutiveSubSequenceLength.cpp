#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int largestConsecutiveSubSequenceLength(vector<int>A);

int main()
{
    vector<int> A={1,2,3,4,5,6,7,8,9,10, 11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30, 59,};
    cout<<largestConsecutiveSubSequenceLength(A);
    return 0;
}
int largestConsecutiveSubSequenceLength(vector<int>A)
{
    map<int, bool>arr, solhash;

    for(auto e:A)
    {
        arr.insert({e, 1});       //inserting data into hash array
    }
    /*
    for(auto e:arr)
    {
        cout<<e.first<<" ";//arr.insert(e);
    }*/
    int prev,nxt, cntr;
    int mxlen=INT_MIN;
    for(int i=0; i<A.size(); i++)
    {
        int cur=A[i];

        prev=nxt=cur;
        cntr=0;
        while(arr[nxt]&&!solhash.count(nxt))  //
        {
            solhash.insert({nxt, 1});
            nxt++;
            cntr++;
        }
        prev--;
        while(arr[prev]&&!solhash.count(prev))    //
        {
            solhash.insert({prev, 1});
            prev--;
            cntr++;
        }

        if(mxlen<cntr)
        {
            mxlen=cntr;
        }

    }
    return mxlen;
}

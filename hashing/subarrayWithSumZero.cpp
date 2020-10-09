#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool checkSubarrayWithSumZero(vector<int> a);
bool checkSubarrayWithSumK(vector<int> a, int k);
int largestLengthOfSubarrayWithSumZero(vector<int> a);
int largestLengthOfSubarrayWithSumK(vector<int> a, int k);

int main()
{
    vector<int> A={1, 6, -3, -4};
    //cout<<checkSubarrayWithSumK(A, 3);
    //cout<<checkSubarrayWithSumZero(A);
    //cout<<largestLengthOfSubarrayWithSumZero(A);
    cout<<largestLengthOfSubarrayWithSumK(A, 3);
    return 0;

}
int largestLengthOfSubarrayWithSumK(vector<int> a, int k)
{
    map<int, int>runningSumIndex;

    int sum=0; int mx=INT_MIN;
    int i=0;
    for(;i<=a.size()-1; i++)
    {
        runningSumIndex.insert({sum, i});
        sum+=a[i];
        if(runningSumIndex.count(sum-k))
        {
            int len=i-runningSumIndex[sum-k]+1;
            if(len>mx)
                mx=len;
        }
    }

    return mx;
}
int largestLengthOfSubarrayWithSumZero(vector<int> a)
{
    map<int, int>runningSumIndex;

    int sum=0; int mx=INT_MIN;
    int i=0;
    for(;i<=a.size()-1; i++)
    {
        runningSumIndex.insert({sum, i});
        sum+=a[i];
        if(runningSumIndex.count(sum))
        {
            int len=i-runningSumIndex[sum]+1;
            if(len>mx)
                mx=len;
        }
    }

    return mx;
}
bool checkSubarrayWithSumK(vector<int> a, int k)
{
    multimap<int, bool>runningSumBool;

    int sum=0;
    int i=0;
    while(i<=a.size()-1)
    {

        //if(sum==k)
          //  return true;
          runningSumBool.insert({sum, true});
    sum+=a[i];
        if(runningSumBool.count(sum-k))
            return true;


        i++;
    }

    return false;
}

bool checkSubarrayWithSumZero(vector<int> a)
{
    multimap<int, bool>runningSumBool;

    int sum=0;
    int i=0;
    while(i<=a.size()-1)
    {
        runningSumBool.insert({sum, true});
        sum+=a[i];
        if(runningSumBool.count(sum))
            return true;

        i++;
    }

    return false;
}

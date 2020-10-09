#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void minNMaxDiff(vector<int> ar);

int main()
{
    vector<int> ar={12, -3, 10, 0};
    minNMaxDiff(ar);
    return 0;
}
void minNMaxDiff(vector<int> ar)
{
    int n=ar.size();
    vector<int> A(n/2), B(n/2);

    for(int i=0, j=n/2; i<n/2; i++, j++)
    {
        A[i]=ar[i];
        B[i]=ar[j];
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int minDiff=0;
    int i=0;
    while(i<n/2)
    {
        minDiff+=abs(A[i]-B[i]);
        i++;
    }
    cout<<minDiff<<" ";

    int maxDiff=0;
    sort(B.begin(), B.end(), std::greater<>{});
    int j=0;
    while(j<n/2)
    {
        maxDiff+=abs(A[j]-B[j]);
        j++;
    }
    cout<<maxDiff<<" ";
}

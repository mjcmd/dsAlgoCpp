#include<iostream>
#include<bits/stdc++.h>

using namespace std;
void bombDefusalSpecialist(int N, int k, vector<int>A);

int main()
{
    vector<int> A={3, 4, 1, 2, 5};
    bombDefusalSpecialist(A.size(), 1, A);
    return 0;

}
void bombDefusalSpecialist(int N, int k, vector<int>A)
{
    map<int, int> indexOf_A;
    for(int i=0; i<N; i++)
    {
        indexOf_A.insert({A[i], i});
    }
    int i=N;
    int start=0;
    for(; i>2; i--)
    {
        int index=indexOf_A[i];
        if(index!=(start))
        {
            int t=A[start];
            A[start]=A[index];
            A[index]=t;
            indexOf_A[A[index]]=index;
            for(auto e: A)
                cout<<e<<" ";
            k--;

        }
        start++;
        cout<<endl;
        cout<<k<<" "<<endl;
        if(k==0)
            break;
    }


    return;
}

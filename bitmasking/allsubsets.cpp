#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;

void allSubsets(vector<int> arr, int i);
int main()
{
    int i=0;
    vector<int> arr={8,5};
    allSubsets(arr, i);
    return 0;
}
void allSubsets(vector<int> arr, int i)
{
    if(i==pow(2, arr.size()))
    {
        return ;
    }
    cout<<"{";
    for(int k = 0; k < arr.size(); k++)
    {
        if(i&(1<<k))
        {
            cout<<arr[k];
            if(!k==arr.size()-1)
                cout<<" ";

        }

    }
    cout<<"}";
    cout<<endl;

    allSubsets(arr, i+1);
    return ;
}

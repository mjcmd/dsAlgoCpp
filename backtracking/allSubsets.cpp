
#include<bits/stdc++.h>

using namespace std;

void allSubset(vector<int> w, vector<int> sol, int i, int sum, int m);
int main()
{
    vector<int>w = {5, 10, 12, 13, 15, 18}, sol;
   // int m=6;
    allSubset(w, sol, 0, 0, 30);
        //for(int k=0; k<4; k++)
            //cout<<sol[k]*w[k]<<endl;
        //cout<<"Not such subset exist!";


    return 0;
}
void allSubset(vector<int> w,vector<int> sol, int i, int sum, int m)
{
    if(sum==m)
    {
        for(int k=0; k<sol.size(); k++)
            cout<<sol[k]<<"\t";
        cout<<endl;

        //sol.pop_back();

        //allSubset(w, sol, i-2);
        //sol[i]=1;
        //cout<<w[i];
        return;
    }
    if(sum<m)
    {
       for(int k=i; k<w.size(); k++)
        {
        //sum=sum+w[k];
        sol.push_back(w[k]);
        allSubset(w, sol, k+1, sum+w[k], m);

        //sum=sum-w[k];
        sol.pop_back();
           // sum=sum-w[k];
            //sol[k]=0;
           // return;
        }
    }

    //return;
    return;
}

/*
#include<bits/stdc++.h>

using namespace std;

void allSubsets(vector<int> arr, vector<int> sol, int i);
int main()
{
    int i = 0;
    vector <int> arr = {1, 2, 3, 4}, sol;
    allSubsets(arr, sol, i);
    return 0;
}

void allSubsets(vector<int> arr, vector<int> sol, int i)
{
    if(i==arr.size())
    {

        //if(!sol.size())
        for(int k=0; k<sol.size(); k++)
            cout<<sol[k]<<" ";
        cout<<endl;
        return;
    }
    allSubsets(arr, sol, i+1);

    sol.push_back(arr[i]);

    allSubsets(arr, sol, i+1);

    return ;

}
*/


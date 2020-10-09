#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class centerRadius
{
    public:
    int c;
    int r;
    bool operator < (const centerRadius& rhs) const { return c<rhs.c; }
    bool operator > (const centerRadius& rhs) const { return c>rhs.c; }
};
int minCirclesRemoved(centerRadius* cr, int m);

int main()
{
    int m;
    cin>>m;
    centerRadius cr[m];
    for(int i=0; i<m; i++)
    {
        cin>>cr[i].c>>cr[i].r;
    }
    cout<<minCirclesRemoved(cr, m);
    return 0;
}

int minCirclesRemoved(centerRadius* cr, int m)
{
    set<centerRadius, less<>>Set;

    for(int i=0; i<m; i++)
    {
        Set.insert(cr[i]);
    }
   /* auto itt=Set.begin();
    for(; itt!=Set.end(); itt++)
    {
        cout<<itt->c<<" "<<itt->r<<endl;
    }
    */
    int c=0;

    auto it=Set.begin();
    auto itcur=it;
    auto itnext=next(it, 1);
    while(itcur!=Set.end()&&itnext!=Set.end())
    {
        //cout<<"Sunil"<<endl;

        int distBWcenters=abs(itcur->c-itnext->c);
        int consecRad=itcur->r+itnext->r;
        while(consecRad>distBWcenters&&itnext!=Set.end())
        {

            //cout<<"kumar"<<endl;

            Set.erase(itnext);
            itnext=next(itcur, 1);  //because set is not linear datastructure where as itnext after its deletion point next element in linear DS by default;
            c++;
            //cout<<c<<" ";
            //it++;
            if(itnext==Set.end())
                break;
            distBWcenters=abs(itcur->c-itnext->c);
            consecRad=itcur->r+itnext->r;
        }

        it++;
        itcur=it;
        if(itcur==Set.end())
            break;
        itnext=next(it, 1);
    }
    return c;
}

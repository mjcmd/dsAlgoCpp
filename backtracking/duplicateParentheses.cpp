#include<bits/stdc++.h>
using namespace std;

bool duplicateParentheses(string exp)
{
    stack<char> s;

    for(int i=0; i<exp.length(); i++)
    {
        char ch=exp[i];
        switch(ch)
        {
            case ')': if(s.top()=='(')
                         {
                             return true;
                         }
                      else
                      {
                          while(s.top()!='(')
                          {
                              s.pop();
                          }
                          s.pop();
                          break;
                      }
            default: s.push(ch);
        }
    }
    return false;
}

int main()
{
    string exp={"(a+(b)+(c+d))"} ;
    if(duplicateParentheses(exp))
        cout<<"Yes";
    else
        cout<<"NO";


    return 0;
}

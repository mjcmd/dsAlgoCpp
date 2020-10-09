#include<bits/stdc++.h>
using namespace std;

bool isBalancedParentheses(vector<char> expr, stack<char>s);
void input(vector<char>&expr)
{
    char ch;
    cin>>ch;
    while(ch!='$')
    {
        expr.push_back(ch);
        cin>>ch;
    }
    cout<<endl;
}
void print(vector<char>expr)
{
    int i=0;
    while(i!=expr.size())
    {
        cout<<expr[i]<<" ";
        i++;
    }
    cout<<endl;
}

bool close(char c)
{
    return c==')'||c=='}'||c==']';
}
bool open(char c)
{
    return c=='('||c=='{'||c=='[';
}
int main()
{
    stack<char>s;
    vector<char>expr;
    //cout<<open('s');
    //cout<<close('d');
    //expr="(5+[9*8]-{7*5}+5)";
    input(expr);
    //print(expr);

    if(isBalancedParentheses(expr, s))//)
        cout<<"Balanced Parentheses Expression!";
    else
        cout<<"Not balanced Parantheses!";

    return 0;
}

bool isBalancedParentheses(vector <char>expr, stack<char>s)
{
    int i=0;
    while(i!=expr.size())
    {

        //cout<<expr[i]<<" ";
        //expr.pop_back();
        if(open(expr[i]))
        {
            s.push(expr[i]);
        }
        if(close(expr[i]))
        {
            if(s.empty())
                return false;

            char c = s.top();
            switch(expr[i])
            {
            case ')': if(c=='(')
                        s.pop();
                      else
                        return false;
                    break;
            case '}': if(c=='{')
                        s.pop();
                      else
                        return false;
                        break;
            case ']': if(c=='[')
                        s.pop();
                      else
                        return false;

            }
        }
        i++;
    }
    if(s.empty())
        return true;
    return false;

}


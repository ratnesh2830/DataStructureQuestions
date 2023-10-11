#include<iostream>
#include<stack>
using namespace std;

class Solution
{
    public:

    bool CheckParentheses(string str)
    {
        stack<char>stack;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]=='{' || str[i]=='[' || str[i]=='(')
            {
                stack.push(str[i]);
            }
            else
            {
                if(stack.empty())
                return false;

                else
                {
                    char c=stack.top();
                    stack.pop();
                    if(str[i]==')' && c=='(' || str[i]=='}' && c=='{' || str[i]==']' && c=='[')
                    continue;
                    else
                    return false;
                }

            }
        }
    if(stack.empty())
        return true;

    return false;
    }
};

int main()
{
    Solution M;
    string str="{[(())]}";
    cout<<M.CheckParentheses(str);
return 0;
}
#include<iostream>
using namespace std;
#include<stack>

class Solution
{
    public:
    string ReverseString(string s)
    {
        stack<string>stack;
        string str="";
        s=s+' ';
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
            {
                stack.push(str);
                str="";
            }
            else
            {
                str=str+s[i];
            }
        }
        str="";
        while(stack.size()>1)
        {
            str=str+stack.top()+' ';
            stack.pop();
        }
        str=str+stack.top();

    return str;
    }
};

int main()
{
    Solution M;
    string s="this is an amazing program";
    cout<<M.ReverseString(s);
return 0;
}
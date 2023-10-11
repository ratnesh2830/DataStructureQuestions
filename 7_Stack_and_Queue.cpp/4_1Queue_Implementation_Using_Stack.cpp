#include<iostream>
using namespace std;
#include<stack>

class Solution
{
    public:

    stack<int>st1,st2;
    void push(int x)
    {
        while(!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }

        st1.push(x);

        while(!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
    }

    int top()
    {
        return st1.top();
    }

    void pop()
    {
        st1.pop();
    }
};

int main()
{
    Solution M;
    M.push(2);
    M.push(3);
    M.push(4);
    M.push(5);

    cout<<M.top();
    M.pop();
    cout<<endl<<M.top();
return 0;


}
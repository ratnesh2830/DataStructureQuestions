#include<iostream>
using namespace std;
#include<stack>

class Solution
{
    public:
    stack<int>input,output;

    void push(int x)
    {
        input.push(x);
    }

    void pop()
    {
        if(!output.empty())
        {
            output.pop();
        }
        else
        {
            while(!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
            output.pop();
        }
    }

    int top()
    {
        if(!output.empty())
        {
            return output.top();
        }
        else
        {
            while(!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
            return output.top();
        }
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
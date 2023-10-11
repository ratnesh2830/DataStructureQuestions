#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution
{
    public:
    stack<int> SortaStack(stack<int>&stack1)
    {
        stack<int>stack2;

        while(!stack1.empty())
        {
            int temp=stack1.top();
            stack1.pop();

            while(!stack2.empty())
            {
                if(temp>=stack2.top())
                {
                    stack2.push(temp);
                    break;
                }
                else
                {
                    stack1.push(stack2.top());
                    stack2.pop();
                }
            }
            if(stack2.empty())
            stack2.push(temp);
        }
    return stack2;
    }
};

int main()
{
    Solution M;
    vector<int>vec={1,1,2};
    stack<int>stack1;

    for(int i=0;i<vec.size();i++)
    {
        stack1.push(vec[i]);
    }
    stack<int>res=M.SortaStack(stack1);
    while(!res.empty())
    {
        cout<<res.top()<<endl;
        res.pop();
    }
return 0;
}
#include<iostream>
using namespace std;
#include<vector>
#include<stack>

class Solution
{
    public:
    vector<int> StockSpan(vector<int>&vec)
    {
        int n=vec.size();
        stack<int>stack;
        vector<int>res(n,0);
        
        for(int i=0;i<n;i++)
        {
            while(!stack.empty() && vec[stack.top()]<=vec[i])
            {
                stack.pop();
            }

            if(!stack.empty())
            {
                res[i]=i-stack.top();
            }
            else
            {
                res[i]=i+1;
            }

            stack.push(i);
        }
    return res;
    }
};
int main()
{
    Solution M;
    vector<int>vec={100,80,60,70,60,75,85};
    vector<int>res=M.StockSpan(vec);
    for(auto i:res)
    {
        cout<<i<<" ";
    }
return 0;
}
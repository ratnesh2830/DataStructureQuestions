#include<iostream>
using namespace std;
#include<vector>
#include<stack>

class Solution
{
    public:
    int LargestRectangle(vector<int>&vec)
    {
        int n=vec.size();
        vector<int>lsmaller(n,0);
        vector<int>rsmaller(n,n-1);
        stack<int>stack;
        int area=0;
        int res=INT_MIN;

        for(int i=0;i<n;i++)
        {
            while(!stack.empty() && vec[stack.top()]>=vec[i])
            {
                stack.pop();
            }

            if(!stack.empty())
            {
                lsmaller[i]=stack.top()+1;
            }

            stack.push(i);
        }
        while(!stack.empty())
        {
            stack.pop();
        }

        for(int i=n-1;i>=0;i--)
        {
            while(!stack.empty() && vec[stack.top()]>=vec[i])
            {
                stack.pop();
            }

            if(!stack.empty())
            {
                rsmaller[i]=stack.top()-1;
            }

            stack.push(i);

            area=((rsmaller[i]-lsmaller[i])+1)*vec[i];
            res=max(res,area);
        }
    
    return res;
    }
};
int main()
{
    Solution M;
    vector<int>vec={2,1,5,6,2,3};
    cout<<M.LargestRectangle(vec);
return 0;
}
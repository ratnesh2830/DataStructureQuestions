#include<iostream>
#include<deque>
#include<vector>
using namespace std;

class Solution
{
    public:
    vector<int> SlidingWindow(vector<int>&vec,int k)
    {
        deque<int>dq;
        vector<int>res;

        for(int i=0;i<vec.size();i++)
        {
            if(!dq.empty() && dq.front()==i-k)
            {
                dq.pop_front();
            }

            while(!dq.empty() && vec[dq.back()]<vec[i])
            {
                dq.pop_back();
            }

            dq.push_back(i);

            if(i>=k-1)
            {
                res.push_back(vec[dq.front()]);
            }
        }
    return res;
    }
};
int main()
{
    Solution M;
    vector<int>vec={4,0,-1,3,5,3,6,8};
    vector<int>res;
    res=M.SlidingWindow(vec,3);
    for(auto i:res)
    {
        cout<<i<<" ";
    }

return 0;
}

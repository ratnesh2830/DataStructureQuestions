#include<iostream>
using namespace std;
#include<vector>

class Solution
{
    public:

    int LargestRectangle(vector<int>&vec)
    {
        int ans=INT_MIN;
        for(int i=0;i<vec.size();i++)
        {
            int res=0;
            for(int j=0;j<vec.size();j++)
            {
                if(vec[j]>=vec[i])
                {
                    res=res+vec[i];
                    ans=max(ans,res);
                }
                else
                {
                    res=0;
                }
            }
        }
    return ans;
    }
};

int main()
{
    Solution M;
    vector<int>vec={2,1,4,4,2,3};
    cout<<M.LargestRectangle(vec);
return 0;
}
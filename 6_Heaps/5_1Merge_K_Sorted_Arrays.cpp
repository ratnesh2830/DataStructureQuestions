#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
class Solution
{
    public:
    vector<int> MergeKsortedArrays(vector<vector<int>>&vec)
    {
        vector<int>res;
        for(int i=0;i<vec.size();i++)
        {
            for(int j=0;j<vec[i].size();j++)
            {
                res.push_back(vec[i][j]);
            }
        }
    sort(res.begin(),res.end());
    return res;
    }   
};

int main()
{
    Solution M;
    vector<vector<int>>vec={{10,20,30},
                            {5,15},
                            {4,9,11}};
    vector<int>res;
    res=M.MergeKsortedArrays(vec);
    for(auto i:res)
    {
        cout<<i<<" ";
    }
return 0;
}
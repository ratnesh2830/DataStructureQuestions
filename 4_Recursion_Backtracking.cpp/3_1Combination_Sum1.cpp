#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution
{
    public:
    void function(int index,int target,vector<int>&vec,vector<vector<int>>&res,vector<int>&ds)
    {
        if(index==vec.size())
        {
            if(target==0)
            {
                sort(ds.begin(),ds.end());
                res.push_back(ds);
            }
        return;
        }

        if(vec[index]<=target)
        {
            ds.push_back(vec[index]);
            function(index,target-vec[index],vec,res,ds);
            ds.pop_back();
        }

        function(index+1,target,vec,res,ds);
    }

    vector<vector<int>> Combination(vector<int>&vec,int target)
    {
        vector<vector<int>>res;
        vector<int>ds;
        function(0,target,vec,res,ds);
    return res;
    }
};
int main()
{
    Solution M;
    vector<int>vec{2,3,2};
    int target=7;
    vector<vector<int>> res;
    res=M.Combination(vec,target);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            cout<<res[i][j]<<" ";
        }
    cout<<endl;
    }
return 0;

}
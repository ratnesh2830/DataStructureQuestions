#include<iostream>
using namespace std;
#include<vector>
#include<set>
#include<algorithm>

class Solution
{
    public:
    void function(int index,int target,vector<int>&vec,vector<int>&ds,set<vector<int>>&set)
    {
        if(index==vec.size())
        {
            if(target==0)
            {
                set.insert(ds);
            }
        return;
        }

    if(vec[index]<=target)
    {
        ds.push_back(vec[index]);
        function(index+1,target-vec[index],vec,ds,set);
        ds.pop_back();
    }
    function(index+1,target,vec,ds,set);

    }

    vector<vector<int>>Combination(vector<int>&vec,int target)
    {
        set<vector<int>>set;
        vector<int>ds;
        function(0,target,vec,ds,set);

    vector<vector<int>> res(set.begin(),set.end());
    return res;
    }
};

int main()
{
    Solution M;
    vector<int>vec{1,2,1,2,1};
    vector<vector<int>>res;
    int target=4;
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



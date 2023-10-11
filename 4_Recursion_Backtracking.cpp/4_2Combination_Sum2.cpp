#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
    public:
    void function(int index,int target,vector<int>&vec,vector<vector<int>>&res,vector<int>&ds)
    {
        
             if(target==0)
             {
              res.push_back(ds);
             return;
            }
        

        for(int i=index;i<vec.size();i++)
        {
            if(i!=index &&vec[i]==vec[i-1])
            continue;

            if(vec[i]>target)
            break;

            ds.push_back(vec[i]);
            function(i+1,target-vec[i],vec,res,ds);
            ds.pop_back();
        }
    }

    vector<vector<int>>Combination(vector<int>&vec,int target)
    {
        vector<vector<int>>res;
        vector<int>ds;
        sort(vec.begin(),vec.end());
        function(0,target,vec,res,ds);
    return res;
    }
};

int main()
{
    Solution M;
    vector<int> vec={2,2,3};
    vector<vector<int>>res;
    int target=7;
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
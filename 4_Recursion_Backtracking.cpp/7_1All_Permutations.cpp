#include<iostream>
#include<vector>
using namespace std;

class Solution
{
    public:
    void function(vector<int>&vec,int k,vector<vector<int>>&res,vector<int>&ds,vector<int>&flag)
    {
        if(k==vec.size())
        {
            res.push_back(ds);
            return;
        }

        for(int i=0;i<vec.size();i++)
        {
            if(flag[i]==0)
            {
                ds[k]=vec[i];
                flag[i]=1;
                function(vec,k+1,res,ds,flag);
                flag[i]=0;
            }
        }
    }

    vector<vector<int>>Permutations(vector<int>&vec)
    {
        vector<int>flag(3,0);
        vector<int>ds(3,0);
        vector<vector<int>>res;

        function(vec,0,res,ds,flag);
    return res;
    }
};

int main()
{
    Solution M;
    vector<int>vec={1,2,3};
    vector<vector<int>>res;
    res=M.Permutations(vec);
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
#include<iostream>
using namespace std;
#include<vector>

class Solution
{
    public:
    void function(int index,vector<int>&vec,vector<vector<int>>&res)
    {
        if(index==vec.size())
        {
            res.push_back(vec);
            return ;
        }

        for(int i=index;i<vec.size();i++)
        {
            swap(vec[index],vec[i]);
            function(index+1,vec,res);
            swap(vec[index],vec[i]);
        }
    }

    vector<vector<int>>Permutation(vector<int>&vec)
    {
        vector<vector<int>>res;
        function(0,vec,res);
        return res;
    }
};
int main()
{
    Solution M;
    vector<int>vec={1,2,3};
    vector<vector<int>>res;
    res=M.Permutation(vec);
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
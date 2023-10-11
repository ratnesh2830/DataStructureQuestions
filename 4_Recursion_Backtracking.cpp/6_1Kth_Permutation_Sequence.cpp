//In this program we are going to print all the possible permutation of the given set
#include<iostream>
using namespace std;
#include<vector>

class Solution
{
    public:
    void function(vector<int>&vec,int k,vector<int>&flag,vector<int>&ds,vector<vector<int>>&res)
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
                function(vec,k+1,flag,ds,res);
                flag[i]=0;
            }
        }
    
    }

    vector<vector<int>>Permutation(vector<int>&vec)
    {
         vector<int>flag(3,0);
         vector<int>ds(3,0);
         vector<vector<int>>res;
         function(vec,0,flag,ds,res);
   
    return res;
    }
};

int main()
{
    Solution P;
    vector<int> vec={1,2,3,4};
    vector<vector<int>>res;
    res=P.Permutation(vec);
    int k=3;
    
 for(int j=0;j<res.size();j++)
    {
        cout<<res[0][j]<<" ";
    }
      

return 0;
}
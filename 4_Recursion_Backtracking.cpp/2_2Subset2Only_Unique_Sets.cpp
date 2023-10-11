#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
class Solution
{
    public:
    void function(int index,vector<int>&vec,vector<int>&vecpair,vector<vector<int>>&res)
    {
        res.push_back(vecpair);
        
        for(int i=index;i<vec.size();i++)
        {
            if(i!=index && vec[i]==vec[i-1])
            continue;

            vecpair.push_back(vec[i]);
            function(i+1,vec,vecpair,res);
            vecpair.pop_back();
        }
    }

    vector<vector<int>> SubsetSum2(vector<int>&vec)
    {
        vector<vector<int>>res;
        vector<int>vecpair;
        int index=0;
        sort(vec.begin(),vec.end());
        function(index,vec,vecpair,res);
    return res;
    }
};

int main()
{
    Solution M;
    vector<int> vec{1,2,2,2,3,3};
    vector<vector<int>> res;
    res=M.SubsetSum2(vec);
    for(int i=0;i<res.size();i++)
    {
        cout<<"[";
        for(int j=0;j<res[i].size();j++)
        {
            cout<<res[i][j];
        }
        cout<<"]";
        cout<<endl;
    }
    cout<<endl;
    cout<<endl<<res.size();
return 0;
}
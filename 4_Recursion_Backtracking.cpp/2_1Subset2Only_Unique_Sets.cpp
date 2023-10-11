#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<set>
class Solution
{
    public:

    void function(int index,vector<int>&vec,int n,vector<int>vecpair,set<vector<int>>&set)
    {
            if(index==n)
            {
                sort(vecpair.begin(),vecpair.end());
                set.insert(vecpair);
                return;
            }
            vecpair.push_back(vec[index]);
            function(index+1,vec,n,vecpair,set);
            vecpair.pop_back();
            function(index+1,vec,n,vecpair,set);
    }
    vector<vector<int>> Substsum(vector<int>&vec,int n)
    {
        vector<int> vecpair;
        set<vector<int>>set;
        int index=0;
        
        
        function(index,vec,n,vecpair,set);
        vector<vector<int>>res(set.begin(),set.end());
        for(int i=0;i<res.size();i++)
        {
            cout<<"{";
            for(int j=0;j<res[i].size();j++)
            {
                cout<<res[i][j];
            }
            cout<<"}";
        cout<<endl;
        }
    return res;
    }
};

int main()
{
    Solution M;
    vector<int> vec{1,2,2};
    M.Substsum(vec,3);
    
return 0;
}
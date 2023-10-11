#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<set>

class Solution
{
    public:
    vector<vector<int>> FourSum(vector<int> &vec,int target)
    {
        int i,j,k,x;
        set<vector<int>> set;
        sort(vec.begin(),vec.end());
        for(i=0;i<vec.size();i++)
        {
            for(j=i+1;j<vec.size();j++)
            {
                for(k=j+1;k<vec.size();k++)
                {
                    x=target-vec[i]-vec[j]-vec[k];
                    if(binary_search(vec.begin()+k+1,vec.end(),x))
                    {
                        vector<int> vec1;
                        vec1.push_back(vec[i]);
                        vec1.push_back(vec[j]);
                        vec1.push_back(vec[k]);
                        vec1.push_back(x);
                        set.insert(vec1);
                    }
                }
            }
        }
   
        vector<vector<int>>res(set.begin(),set.end());
    
    
    return res;
    }
};

int main()
{
    Solution M;
    vector<int> vec{4,4,4,3,3,2,2,1,1,1};
    vector<vector<int>> res;
    int target=9;
    res=M.FourSum(vec,target);
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
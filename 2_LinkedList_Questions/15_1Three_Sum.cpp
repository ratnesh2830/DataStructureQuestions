#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<set>

class Solution
{
    public:
    vector<vector<int>> ThreeSum(vector<int> &vec)
    {
        set<vector<int>>set;

        for(int i=0;i<vec.size()-2;i++)
        {
            for(int j=i+1;j<vec.size()-1;j++)
            {
                int target=vec[i]+vec[j];
                for(int k=j+1;k<vec.size();k++)
                    {
                        if(target+vec[k]==0)
                        {
                            vector<int> vec1;
                            vec1.push_back(vec[i]);
                            vec1.push_back(vec[j]);
                            vec1.push_back(vec[k]);
                            sort(vec1.begin(),vec1.end());
                            set.insert(vec1);
                        }
                    }
            }
        }
    vector<vector<int>> res(set.begin(),set.end());
    return res;
    }
};
int main()
{
Solution M;
vector<int> vec{-1,0,1,2,-1,-4};
vector<vector<int>> res;
res=M.ThreeSum(vec);
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
#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
//using hashing the best approach for 2 sum
class Solution
{
    public:
    vector<int> Twosum(vector<int> &vec,int x)
    {
        vector<int> res;
        unordered_map<int,int> m;

        for(int i=0;i<vec.size();i++)
        {
            if(m.find(x-vec[i])!=m.end())
            {
                res.push_back(m[x-vec[i]]);
                res.push_back(i);
                return res;
            }
            else
            m[vec[i]]=i;
        }
    return res;

    }
};

int main()
{
    Solution M;
    vector<int> vec{2,3,7,15,5,19};
    vector<int> res;
    int target=20;
    res=M.Twosum(vec,target);
    for(auto it:res)
    {
        cout<<it<<" ";
    }
return 0;
}
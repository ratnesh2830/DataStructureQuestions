#include<iostream>
using namespace std;
#include<vector>
#include<map>

class Solution
{
    public:
    vector<int>CountDistinctElements(vector<int>&num,int k)
    {
        vector<int>res;

        if(num.size()==0)
        return res;

        map<int,int>map;
        for(int i=0;i<num.size();i++)
        {
            if(i<k)
            {
                map[num[i]]++;
            }
            else
            {
                res.push_back(map.size());
                if(map[num[i-k]]==1)
                {
                    map.erase(num[i-k]);
                }
                else
                {
                    map[num[i-k]]--;
                }
                map[num[i]]++;
                if(i==num.size()-1)
                res.push_back(map.size());
            }
        }  
    return res;
    }
};

int main()
{
    vector<int>num={1,2,2,1,3,2,1,3};
    Solution M;
    vector<int>res=M.CountDistinctElements(num,3);
    for(auto i:res)
    {
        cout<<i<<" ";
    }
return 0;
}
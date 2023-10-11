#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
#include<algorithm>

bool comp(pair<int,int> &p1,pair<int,int>&p2)
{
    if(p1.second==p2.second)
    return p1.first>p2.first;
    else
    return p1.second>p2.second;

}
class Solution
{
    public:
    vector<pair<int,int>>KmostFrequentElements(vector<int>&vec,int k)
    {
        unordered_map<int,int>map;
        vector<pair<int,int>>res;

        for(int i=0;i<vec.size();i++)
        {
            map[vec[i]]++;
        }

        for(auto it=map.begin();it!=map.end();it++)
        {
            res.push_back(*it);
        }

        sort(res.begin(),res.end(),comp);
    return res;
    }
};

int main()
{
    Solution M;
    vector<int>vec={7, 10, 11, 5, 2, 5, 5, 7, 11, 8, 9};
    int k=4;
    vector<pair<int,int>>res=M.KmostFrequentElements(vec,k);
    for(int i=0;i<k;i++)
    {
        cout<<res[i].first<<" "<<res[i].second<<endl;
    }
return 0;
}
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;

struct comp
{
    bool operator()(pair<int,int>&p1,pair<int,int>&p2)
    {
        if(p1.second==p2.second)
        return p1.first>p2.first;

    return p1.second>p2.second;
    }
};
class Solution
{
    public:

    vector<pair<int,int>> KMostFrequentElements(vector<int>&vec,int k)
    {
        unordered_map<int,int>map;
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp>pq;
        vector<pair<int,int>>res;
        for(int i=0;i<vec.size();i++)
        {
            map[vec[i]]++;
        }

        for(auto it=map.begin();it!=map.end();it++)
        {
            pq.push({it->first,it->second});

            if(pq.size()>k)
            pq.pop();
        }

        for(int i=0;i<k;i++)
        {
            res.push_back(pq.top());
            pq.pop();
        }
    reverse(res.begin(),res.end());
    return res;
    }
};

int main()
{
    Solution M;
    vector<int>vec={7, 10, 11, 5, 2, 5, 5, 7, 11, 8, 9,11};
    int k=4;
    vector<pair<int,int>>res=M.KMostFrequentElements(vec,k);
    for(int i=0;i<k;i++)
    {
        cout<<res[i].first<<" "<<res[i].second<<endl;
    }
return 0;
}
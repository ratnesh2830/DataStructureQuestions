#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct data
{
    int value;
    int apos;
    int vpos;
};

struct comp
{
    bool operator()(data &d1,data &d2)
    {
        return d1.value>d2.value;
    }
};


class Solution
{
    public:

    vector<int>MergeKSortedAraays(vector<vector<int>>&vec)
    {
        vector<int>res;
        int k=vec.size();
        priority_queue<data,vector<data>,comp>pq;
        for(int i=0;i<k;i++)
        {
            data d{vec[i][0],i,0};
            pq.push(d);
        }
        while(!pq.empty())
        {
            data d=pq.top();
            pq.pop();
            res.push_back(d.value);
            int ap=d.apos;
            int vp=d.vpos;
            if(vp+1<vec[ap].size())
            {
                data d1{vec[ap][vp+1],ap,vp+1};
                pq.push(d1);
            }
        }
    return res;
    }
};

int main()
{
    Solution M;
    vector<vector<int>>vec={{10,20,30},
                            {5,15},
                            {4,9,11}};
    vector<int>res;
    res=M.MergeKSortedAraays(vec);
    for(auto i:res)
    {
        cout<<i<<" ";
    }
return 0;
}
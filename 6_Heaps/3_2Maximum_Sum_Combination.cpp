#include<iostream>
#include<vector>
using namespace std;
#include<set>
#include<queue>
#include<algorithm>
class Solution
{
    public:
    vector<int> MaximumSum(vector<int>&A,vector<int>&B,int k)
    {
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        priority_queue<pair<int,pair<int,int>>>pq;
        set<pair<int,int>>set;
        vector<int>res;
        int n=A.size();
        pq.push({A[n-1]+B[n-1],{n-1,n-1}});
        set.insert({n-1,n-1});

        for(int i=0;i<k;i++)
        {
            auto top=pq.top();
            pq.pop();
            res.push_back(top.first);
            int L=top.second.first;
            int R=top.second.second;

            if(L>0 && R>0 && (set.find({L-1,R})==set.end()))
            {
                pq.push({A[L-1]+B[R],{L-1,R}});
                set.insert({L-1,R});
            }   
            if(L>0 && R>0 && (set.find({L,R-1})==set.end()))
            {
                pq.push({A[L]+B[R-1],{L,R-1}});
                set.insert({L,R-1});
            }
        }
    return res;
    }
};
int main()
{
    Solution M;
    vector<int>A={4,2,5,1};
    vector<int>B={8,0,3,5};
    vector<int>res=M.MaximumSum(A,B,4);
    for(auto x:res)
    {
        cout<<x<<endl;
    }
return 0;
}
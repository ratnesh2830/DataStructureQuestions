#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<utility>

struct Job
{
    int jobid;
    int deadline;
    int profit;
};

bool comparator(Job a,Job b)
{
    if(a.profit>b.profit)
    return true;

return false;
    
}
class Solution
{
    public:

    pair<int,int> MaxProfit(Job A[],int n)
    {
        pair<int,int>res;
        sort(A,A+n,comparator);

        int maxi=0;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,A[i].deadline);
        }

        vector<int> slot(maxi+1,-1);
        int countjob=0;
        int totalprofit=0;

        for(int i=0;i<n;i++)
        {
            for(int j=A[i].deadline;j>0;j--)
            {
                if(slot[j]==-1)
                {
                    slot[j]=A[i].jobid;
                    countjob++;
                    totalprofit+=A[i].profit;
                    break;
                }
            }
        }
    res.first=countjob;
    res.second=totalprofit;

    for(auto it:slot)
    {
        if(it!=-1)
        cout<<it<<" ";
    }
    cout<<endl;
    return res;
    }
};

int main()
{
    Solution M;
    Job A[]={{1,4,20},{2,1,10},{3,1,40},{4,1,30}};
    pair<int,int> res;
    res=M.MaxProfit(A,4);
    for(int i=0;i<4;i++)
    {
        cout<<A[i].profit<<" ";
    }
    cout<<endl;
    cout<<res.first<<" "<<res.second;
    
return 0;
}
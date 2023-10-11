#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Solution
{
    public:
    vector<int> CountDistictElements(vector<int>&num,int k)
    {
        vector<int>res;
        if(num.size()==0)
        return res;

        int n=num.size();
        for(int i=0;i<n-k+1;i++)
        {
            int distcount=0;
            for(int j=i;j<i+k;j++)
            {
                distcount=distcount+1;
                for(int l=i;l<j;l++)
                {
                    if(num[j]==num[l])
                    {
                        distcount=distcount-1;
                        break;
                    }
                }
            }
        res.push_back(distcount);
        }
    return res;
    }
};

int main()
{
    vector<int>num={1,2,2,1,3,1,1,3};
    Solution M;
    vector<int>res;
    int k=3;
    res=M.CountDistictElements(num,k);
    for(auto i:res)
    {
        cout<<i<<" ";
    }
return 0;
}
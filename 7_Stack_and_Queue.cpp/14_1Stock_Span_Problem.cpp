#include<iostream>
using namespace std;
#include<vector>

class Solution
{
    public:
    vector<int> StockSpan(vector<int>&vec)
    {
        int n=vec.size();
        vector<int>res(n,0);
        for(int i=n-1;i>=0;i--)
        {
            int count=0;
            for(int j=i;j>=0;j--)
            {
                if(vec[j]<=vec[i])
                {
                    count++;
                }
                else
                break;
            }
        res[i]=count;
        }
    return res;
    }
};

int main()
{
    Solution M;
    vector<int>vec={100,80,60,70,60,75,85};
    vector<int>res=M.StockSpan(vec);
    for(auto i:res)
    {
        cout<<i<<" ";
    }
return 0;
}
#include<iostream>
#include<vector>
using namespace std;

class Solution
{
    public:
    vector<int> MaximumOfMinimum(vector<int>&vec)
    {
        int n=vec.size();
        vector<int>res;
        int ansmaxi=INT_MIN;
        int ansmini=INT_MAX;
        int k=2;
        while(k<=n)
        {
            ansmaxi=INT_MIN;
            for(int i=0;i<(n-k)+1;i++)
            {
                ansmini=INT_MAX;
                for(int j=i;j<i+k;j++)
                {
                    ansmini=min(ansmini,vec[j]);
                }
            ansmaxi=max(ansmaxi,ansmini);
            }
        res.push_back(ansmaxi);
        k++;
        }
    return res;
    }
};

int main()
{
    Solution M;
    vector<int>vec={10,20,30,50,10,70,30};
    vector<int>res=M.MaximumOfMinimum(vec);
    for(auto i:res)
    {
        cout<<i<<" ";
    }
return 0;
}
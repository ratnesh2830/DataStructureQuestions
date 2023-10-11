#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Solution
{
    public:
    int LongestS(vector<int> &vec)
    {
        int i,j,count=0;
        vector<int> res;
        
        if(vec.empty())
        return 0;

        for(i=0;i<vec.size();i++)
        {
            int sum=0;
            count=0;
            for(j=i;j<vec.size();j++)
            {
                sum=sum+vec[j];
                count++;
                if(sum==0)
                {
                    res.push_back(count);
                }
            }
        }
    return res.empty()?0:*max_element(res.begin(),res.end());

    }
};

int main()
{
    Solution M;
    vector<int> vec{1,1,0,0,0,0,2,-2};
    cout<<M.LongestS(vec);
return 0;
}
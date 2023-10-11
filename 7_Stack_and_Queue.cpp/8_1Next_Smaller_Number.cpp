#include<iostream>
using namespace std;
#include<vector>
#include<stack>

class Solution
{
    public:
    vector<int> NextSmallerElement(vector<int>&vec)
    {
        int n=vec.size();
        vector<int>res;
        for(int i=0;i<n;i++)
        {
            for(int j=(i+1)%n;j<n;j=(j+1)%n)
            {
                if(vec[j]<vec[i])
                {
                    res.push_back(vec[j]);
                    break;
                }
                else
                {
                    if(j==i)
                    {
                    res.push_back(-1);
                    break;
                    }
                }
            }
        }
    return res;
    }
};
int main()
{
    Solution M;
    vector<int>vec={1,2,3,4,5,6,7};
    vector<int>res=M.NextSmallerElement(vec);

    for(auto i:res)
    {
        cout<<i<<" ";
    }
return 0;
}
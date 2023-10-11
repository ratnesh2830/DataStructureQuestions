#include<iostream>
using namespace std;
#include<vector>

class Solution
{
    public:
    int TappingWater(vector<int> &vec)
    {
        if(vec.empty())
        return 0;
        int totalwater=0;
        
        for(int i=0;i<vec.size();i++)
        {
            int j=i;
            int maxileft=INT_MIN;
            int maxiright=INT_MIN;
            while(j>=0)
            {
                maxileft=max(maxileft,vec[j]);
                j--;
            }
            j=i;
            while(j<vec.size())
            {
                maxiright=max(maxiright,vec[j]);
                j++;
            }
        totalwater+=min(maxileft,maxiright)-vec[i];
        }
    return totalwater;
    }
};

int main()
{
    Solution M;
    vector<int>vec{4,2,0,3,2,5};
    cout<<M.TappingWater(vec);
return 0;
}
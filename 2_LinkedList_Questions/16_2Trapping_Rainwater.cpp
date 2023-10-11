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

        int maxi=INT_MIN;
        vector<int>prefix(vec.size(),0);
        vector<int>suffix(vec.size(),0);

        for(int i=0;i<vec.size();i++)
        {
            maxi=max(maxi,vec[i]);
            prefix[i]=maxi;
        }
        maxi=INT_MIN;
        for(int i=vec.size()-1;i>=0;i--)
        {
            maxi=max(maxi,vec[i]);
            suffix[i]=maxi;
        }
    int totalwater=0;
        for(int i=0;i<vec.size();i++)
        {
            totalwater+=min(prefix[i],suffix[i])-vec[i];
        }
    return totalwater;
    }
};

int main()
{
    Solution M;
    vector<int>vec{0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<M.TappingWater(vec);
return 0;
}
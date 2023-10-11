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
        
        int l=0;
        int r=vec.size()-1;
        int leftmost=0;
        int rightmost=0;
        int res=0;

        while(l<r)
        {
            if(vec[l]<=vec[r])
            {
                if(vec[l]>=leftmost)
                {
                    leftmost=vec[l];
                }
                else
                {
                    res+=leftmost-vec[l];
                }
            l++;
            }
            else if(vec[l]>vec[r])
            {
                if(vec[r]>=rightmost)
                {
                    rightmost=vec[r];
                }
                else
                {
                    res+=rightmost-vec[r];
                }
            r--;
            }
        }
    return res;

    }
};

int main()
{
    Solution M;
    vector<int>vec{0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<M.TappingWater(vec);
return 0;
}
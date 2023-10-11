#include<iostream>
using namespace std;
#include<vector>

class Solution
{
    public:
    
    int BSrotatedArray(vector<int>&vec,int target)
    {
        for(int i=0;i<vec.size();i++)
        {
            if(target==vec[i])
            return i;
        }
    return -1;
    }
};
int main()
{
    Solution M;
    vector<int>vec={4,5,6,7,0,1,2,3};
    int target=9;
    cout<<M.BSrotatedArray(vec,target);
return 0;
}
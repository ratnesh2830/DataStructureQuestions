#include<iostream>
using namespace std;
#include<vector>

class Solution
{
    public:
    
    int BSrotatedArray(vector<int>&vec,int target)
    {
        int low=0;
        int high=vec.size()-1;

        while(low<=high)
        {
            int mid=(low+high)/2;

            if(vec[mid]==target)
            return mid;

            if(vec[low]<=vec[mid])
            {
                if(target>=vec[low] && target<=vec[mid])
                {
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }
            }
            else
            {
                if(target>=vec[mid] && target<=vec[high])
                {
                    low=mid+1;    
                }
                else
                {
                    high=mid-1;
                }
            }
        }
    return -1;
    } 
};

int main()
{
    Solution M;
    vector<int>vec{7,8,9,10,11,12,0,1,2,3,4,5,6};
    int target=12;
    cout<<M.BSrotatedArray(vec,target);
return 0;
}
#include<iostream>
#include<vector>
using namespace std;

class Solution
{
    public:
    int SearchSingle(vector<int>&vec)
    {
        int low=0;
        int high=vec.size()-2;

        while(low<=high)
        {
            int mid=(low+high)/2;
            
            if(vec[mid]==vec[mid^1])
                low=mid+1;
            else
                high=mid-1;
        }
    return vec[low];
    }
};

int main()
{
    Solution M;
    vector<int>vec{1,1,2,3,3,4,4,5,5};
    cout<<M.SearchSingle(vec);
return 0;
}
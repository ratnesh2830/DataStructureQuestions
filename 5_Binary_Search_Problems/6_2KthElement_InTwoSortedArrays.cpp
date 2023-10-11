#include<iostream>
#include<vector>
using namespace std;

class Solution
{
    public:
    int KthElement(vector<int>&arr1,vector<int>&arr2,int k)
    {
        if(arr2.size()<arr1.size())
        return KthElement(arr2,arr1,k);

        int n=arr1.size();
        int m=arr2.size();

        int low=max(0,k-m);
        int high=min(n,k);

        while(low<=high)
        {
            int mid1=(low+high)/2;
            int mid2=k-mid1;

            int l1=mid1==0?INT_MIN:arr1[mid1-1];
            int l2=mid2==0?INT_MIN:arr2[mid2-1];
            int r1=mid1==n?INT_MAX:arr1[mid1];
            int r2=mid2==m?INT_MAX:arr2[mid2];

            if(l1<=r2 && l2<=r1)
            {
                return max(l1,l2);
            }
            else if(l1>r2)
            {
                high=mid1-1;
            }
            else
            {
                low=mid1+1;
            }
        }
    return -1;
    }
};

int main()
{
    Solution M;
    vector<int>arr1={2,3,6,7,9};
    vector<int>arr2={1,4,8,10};
    cout<<M.KthElement(arr1,arr2,7);
return 0;
}
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
    public:

    double MedianofTwosortedArrays(vector<int>&arr1,vector<int>&arr2)
    {
     if(arr2.size()<arr1.size())
     return MedianofTwosortedArrays(arr2,arr1);

     int n=arr1.size();
     int m=arr2.size();
    
     int low=0;
     int high=n;

     while(low<=high)
     {
        int mid1=(low+high)/2;
        int mid2=((n+m+1)/2)-mid1;

        int l1=mid1==0?INT_MIN:arr1[mid1-1];
        int l2=mid2==0?INT_MIN:arr2[mid2-1];
        int r1=mid1==n?INT_MAX:arr1[mid1];
        int r2=mid2==m?INT_MAX:arr2[mid2];

        if(l1<=r2 && l2<=r1)
        {
            if((n+m)%2==0)
            {
                return (max(l1,l2)+min(r1,r2))/2.0;
            }
            else
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
    return 0.0;
    }
};
int main()
{
    Solution M;
    vector<int>arr1={1,3,4,7,10,12};
    vector<int>arr2={2,3,5,5};
    cout<<M.MedianofTwosortedArrays(arr1,arr2);
return 0;
}

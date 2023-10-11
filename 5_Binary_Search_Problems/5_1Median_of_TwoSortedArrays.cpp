#include<iostream>
#include<vector>
using namespace std;

class Solution
{
    public:
    double MedianOFtwoSortedArrays(vector<int>&arr1,vector<int>&arr2)
    {
        int n=arr1.size();
        int m=arr2.size();
        int i=0,j=0;
        vector<int>res;
        while(i<n && j<m)
        {
            if(arr1[i]<=arr2[j])
            {
                res.push_back(arr1[i++]);
            }
            else
            {
                res.push_back(arr2[j++]);
            }
        }
    while(i<n)
    {
        res.push_back(arr1[i++]);
    }
    while(j<m)
    {
        res.push_back(arr2[j]);
    }

    if((n+m)%2==0)
    {
        return (res[(n+m)/2]+res[((n+m)/2)-1])/2.0;
    }
    
    return res[(n+m)/2];
    }    
};
int main()
{
    Solution M;
    vector<int>arr1={1,3,4,7,10,12};
    vector<int>arr2={2,3,5,5};
    cout<<M.MedianOFtwoSortedArrays(arr1,arr2);
return 0;
}
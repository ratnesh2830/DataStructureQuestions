#include<iostream>
using namespace std;
#include<vector>

class Solution
{
    public:
    int Totalcount(vector<vector<int>>&matrix,int i,int mid)
    {
        int low=0;
        int high=matrix[i].size()-1;

        while(low<=high)
        {
            int md=(low+high)/2;
            if(matrix[i][md]<=mid)
            low=md+1;
            else
            high=md-1;
        }
    return low;
    }

    int Median(vector<vector<int>>&matrix,int n,int m)
    {
        int low=1;
        int high=1e+9;
        while(low<=high)
        {
            int mid=(low+high)/2;
            int count=0;
            for(int i=0;i<n;i++)
            {
                count=count+Totalcount(matrix,i,mid);
            }
            if(count<=(n*m)/2)
            low=mid+1;
            else
            high=mid-1;
        }
    return low;
    }
};

int main()
{
    vector<vector<int>>matrix={{1,3,2},
                               {2,2,9},
                               {3,6,9}};
    Solution M;
    cout<<M.Median(matrix,3,3);
return 0;
}

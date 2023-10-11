#include<iostream>
#include<vector>
using namespace std;

class Solution
{
    public:

    bool isValid(vector<int>&vec,int mid,int k)
    {
        int student=1;
        int sum=0;

        for(int i=0;i<vec.size();i++)
        {
            if(vec[i]>mid)
            return false;

            sum=sum+vec[i];

            if(sum>mid)
            {
                student++;
                sum=vec[i];
            }
        }
        if(student>k)
        return false;
    
    return true;

    }
    int AllocatePages(vector<int>&vec,int k)
    {
        if(k>vec.size() || k==0)
        return -1;

        int high=0,low=INT_MAX;
        for(int i=0;i<vec.size();i++)
        {
            high=high+vec[i];
            low=min(low,vec[i]);
        }

        while(low<=high)
        {
            int mid=(low+high)/2;

            if(isValid(vec,mid,k)==true)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
    return low;
    }
};

int main()
{
    Solution M;
    vector<int> vec={12,40,13,1};
    cout<<M.AllocatePages(vec,1);
return 0;
}

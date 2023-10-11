#include<iostream>
using namespace std;
#include<vector>

class Solution
{
    public:
    bool Search(vector<vector<int>>&vec,int x)
    {
        if(vec.size()==0)
        return false;

        int l,h,mid,i,j;
        l=0;
        h=(vec.size()*vec[0].size())-1;
        while(l<=h)
        {
            mid=(l+h)/2;
            i=mid/vec[0].size();
            j=mid%vec[0].size();

            if(x==vec[i][j])
            return true;
            
            else if(x<vec[i][j])
            h=mid-1;
            
            else
            l=mid+1;
        }
    return false;
    }
};

int main()
{
    Solution M;
    vector<vector<int>>vec{{1,3,5,7},
                            {10,11,16,20},
                            {23,30,34,60}};
    int target= 33;
    cout<<M.Search(vec,target);
return 0;
}
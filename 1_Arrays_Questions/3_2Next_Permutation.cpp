#include<iostream>
using namespace std;
#include<vector>

class Solution
{
    public:
    void Next(vector<int>&vec)
    {
        int i,j;

        if(vec.size()==0)
        {
            cout<<"empty vector";
            exit(0);
        }
        int n=vec.size();
        int index;
        for(i=n-2;i>=0;i--)
        {
            if(vec[i]<vec[i+1])
            {
                index=i;
                break;
            }
        }
        if(i>=0)
        {
            for(i=n-1;i>=0;i--)
            {
                if(vec[i]>vec[index])
                {
                    swap(vec[i],vec[index]);
                    break;
                }
            }
            for(i=index+1,j=n-1;i<j;i++,j--)
            {
                swap(vec[i],vec[j]);
            }
        }
        else
        {
            for(i=0,j=n-1;i<j;i++,j--)
            {
                swap(vec[i],vec[j]);
            }
        }
               
    }
};

int main()
{
    Solution M;
    vector<int> vec{1,3,5,4,2};
    M.Next(vec);
    for(auto it:vec)
    {
        cout<<it<<" ";
    }
return 0;
}
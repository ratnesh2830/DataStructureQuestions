#include<iostream>
#include<vector>
using namespace std;

class Solution
{
    public:

    void MaxHeapify(vector<int>&vec)
    {
        int n=vec.size()-1;
        int i,j;

        for(int k=n/2;k>=1;k--)
        {
            i=k;
            j=2*k;

            while(j<=n)
            {
                if(j<n && vec[j]<vec[j+1])
                {
                    j=j+1;
                }
                if(vec[i]<vec[j])
                {
                    swap(vec[i],vec[j]);
                    i=j;
                    j=2*j;
                }
            else
            break;
            }
        }
    }

    void deleteheap(vector<int>&vec,int n)
    {
        int x,i,j;
        x=vec[1];
        vec[1]=vec[n];
        vec[n]=x;
        i=1;
        j=2*i;

        while(j<=n-1)
        {
            if(j<n-1 && vec[j]<vec[j+1])
            j=j+1;

            if(vec[i]<vec[j])
            {
                swap(vec[i],vec[j]);
                i=j;
                j=2*j;
            }
            else
            break;
        }
        
    }
};

int main()
{
    Solution M;
    vector<int>vec={0,11,7,31,20,21,19,18};
    M.MaxHeapify(vec);
    for(int i=vec.size()-1;i>1;i--)
    {
        M.deleteheap(vec,i);
    }

    for(int i=1;i<vec.size();i++)
    {
        cout<<vec[i]<<" ";
    }
return 0;
}
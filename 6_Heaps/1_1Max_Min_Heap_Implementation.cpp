//In this program we are going to create min and max heap using normal method and than delete function
#include<iostream>
#include<vector>
using namespace std;

class Solution
{
    public:
    void maxheap(vector<int>&vec,int k)
    {
        if(k==0 || k==1)
        return;

        int temp=vec[k];

        while(k>1 && temp>vec[k/2])
        {
            vec[k]=vec[k/2];
            k=k/2;
        }
        vec[k]=temp;
    }

    void Minheap(vector<int>&vec,int k)
    {
        if(k==0 ||k==1)
        return;

        int temp=vec[k];
        while(k>1 && temp<vec[k/2])
        {
            vec[k]=vec[k/2];
            k=k/2;
        }
        vec[k]=temp;
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
            if(j<n-1 && vec[j]>vec[j+1])
            j=j+1;

            if(vec[i]>vec[j])
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
    for(int i=0;i<vec.size();i++)
    {
        M.Minheap(vec,i);
    }
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
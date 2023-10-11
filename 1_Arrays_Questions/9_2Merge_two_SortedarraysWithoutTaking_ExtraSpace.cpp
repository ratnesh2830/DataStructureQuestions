#include<iostream>
using namespace std;
#include<vector>


class Solution
{
    public:

    void Merge(vector<int> &vec1,vector<int>&vec2)
    {
        int i,j,gap,n,m,k;
        n=vec1.size();
        m=vec2.size();
        if((n+m)%2==0)
        k=(n+m)/2;
        else
        k=(n+m)+1;
        
        for(gap=k;gap>0;gap=gap/2)
        {
            //checking in first array
            for(i=0;i+gap<n;i++)
            {
                if(vec1[i]>vec1[i+gap])
                    swap(vec1[i],vec1[i+gap]);
            }

            //checking in both the arrays
            if(gap>n)
                j=gap-n;
            else
                j=0;
            
            while(i<n && j<m)
            {
                if(vec1[i]>vec2[j])
                swap(vec1[i],vec2[j]);
                
                i++,j++;
            }
            //checking in 2nd array 
            for(j=0;j+gap<vec2.size();j++)
            {
                if(vec2[j]>vec2[j+gap])
                    swap(vec2[j],vec2[j+gap]);
            }
        }

    }
};

int main()
{
    Solution M;
    vector<int> vec1{4,6,8,10,12};
    vector<int> vec2{0,7,31};
    M.Merge(vec1,vec2);
    for(int i=0;i<vec1.size();i++)
    {
        cout<<vec1[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<vec2.size();i++)
    {
        cout<<vec2[i]<<" ";
    }
return 0;
}
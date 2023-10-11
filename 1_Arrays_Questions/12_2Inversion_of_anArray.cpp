#include<iostream>
using namespace std;
#include<vector>

class Solution
{
    public:

    int Merge(vector<int> &vec,vector<int> &temp,int l,int mid,int h)
    {
        int i,j,k,count=0;
        i=k=l;
        j=mid+1;

        while(i<=mid && j<=h)
        {
            if(vec[i]<=vec[j])
            temp[k++]=vec[i++];
            
            else
            {
                temp[k++]=vec[j++];
                count=count+(mid+1-i);
            }
        }

    while(i<=mid)
    temp[k++]=vec[i++];
    while(j<=h)
    temp[k++]=vec[j++];

    for(i=l;i<=h;i++)
        vec[i]=temp[i];
    
    
    return count;
    }

    int Inversion(vector<int> &vec,vector<int> &temp,int l,int h)
    {
        int mid,count=0;
        if(l<h)
        {
            mid=(l+h)/2;
            count+=Inversion(vec,temp,l,mid);
            count+=Inversion(vec,temp,mid+1,h);
            count+=Merge(vec,temp,l,mid,h);
        }
    return count;
    }
};

int main()
{
    Solution M;
    vector<int> vec{5,7,6};
    vector<int> temp(vec.size());
    cout<<M.Inversion(vec,temp,0,vec.size()-1);
return 0;
}
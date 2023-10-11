#include<iostream>
using namespace std;
#include<vector>

class Solution
{
    public:
//Bruteforce approach Worst case
    int ReversePairs(vector<int> &vec)
    {
        int res;
        int i,j;
        int count=0;
        
        for(i=0;i<vec.size();i++)
        {
            for(j=i+1;j<vec.size();j++)
            {
                if(vec[i]>2*vec[j])
                {
                    count++;
                }
            }
        }
    return count;
    }

// best case or Optimized approach
    int Merge(vector<int> &vec,vector<int>&temp,int l,int mid,int h)
    {
        int i,j,k;
        int count=0;
        i=k=l;
        j=mid+1;
        
        while(i<=mid && j<=h)
        {
            if(vec[i]>2*vec[j])
            {
                count=count+(mid+1-i);
                j++;
            }
            else
            i++;
        }
        
        i=k=l;
        j=mid+1;
        
        while(i<=mid && j<=h)
        {
            if(vec[i]<=vec[j])      
            temp[k++]=vec[i++];      
            else            
            temp[k++]=vec[j++];
                   
        }
        
    while(i<=mid)
    temp[k++]=vec[i++];

    while(j<=h)
    temp[k++]=vec[j++];

    for(i=l;i<=h;i++)
    vec[i]=temp[i];

    return count;
    }


    int ReverseCount(vector<int>&vec,vector<int>&temp,int l,int h)
    {
        int count=0;
        int mid=0;
        if(l<h)
        {
            mid=(l+h)/2;
            count+=ReverseCount(vec,temp,l,mid);
            count+=ReverseCount(vec,temp,mid+1,h);
            count+=Merge(vec,temp,l,mid,h);
        }
    return count;
    }

    
};

int main()
{
    Solution M;
    vector<int> vec{40,25,19,12,9,6,2};
    vector<int> temp(1);
    cout<<M.ReverseCount(vec,temp,0,vec.size()-1);
return 0;
}
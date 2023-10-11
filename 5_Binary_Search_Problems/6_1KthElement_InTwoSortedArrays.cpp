#include<iostream>
using namespace std;
#include<vector>

class Solution
{
    public:
    int KthElement(vector<int>&vec1,vector<int>&vec2,int k)
    {
        int n=vec1.size();
        int m=vec2.size();
        int i=0;
        int j=0;
        int count=0;
            while(i<n && j<m)
            {   
                if(vec1[i]<=vec2[j])
                {
                    count++;
                    if(count==k)
                    return vec1[i];

                    i++;
                    
                }
                else
                {
                    count++;
                    if(count==k)
                    return vec2[j];

                    j++;
                } 
            }

    while(i<n)
    {

        count++;
        if(count==k)
        return vec1[i];

        i++;
    }
    while(j<m)
    {
        count++;
        if(count==k)
        return vec2[j];

        j++;
    }

    return -1;
    }
};

int main()
{
     vector<int>vec1={2,3,6,7,9};
     vector<int>vec2={1,4,8,10};
    Solution M;
    cout<<M.KthElement(vec1,vec2,8);
return 0;
}
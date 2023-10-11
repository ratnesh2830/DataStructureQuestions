#include<iostream>
using namespace std;

class MaxSubArray
{
public:
    int A[9]={-2,1,-3,4,-1,2,1,-5,4};
    int n=9;

public:
    void Subarray();
};

void MaxSubArray::Subarray()
{
        int i,j,k,x,y,max,sum=0;
        max=INT_MIN;

        for(i=0;i<n;i++)
        {
            
            for(j=i;j<n;j++)
            {  
                sum=0;
                for(k=i;k<=j;k++)
                {
                    sum=sum+A[k];
                }
            if(sum>max)
                {
                    max=sum;
                    x=i;
                    y=j;
                }
            }
        }

cout<<"From index "<<x<<" to "<<y<<" and the sum is: "<<max;
}


int main()
{
    MaxSubArray M;
    M.Subarray();
return 0;
}
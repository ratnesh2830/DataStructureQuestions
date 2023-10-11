#include<iostream>
using namespace std;

class MaxSubArray
{
public:
    int A[9]={1,2,7,-4,3,2,-10,9,1};
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
            sum=0;
            for(j=i;j<n;j++)
            { 
              sum=sum+A[j];
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
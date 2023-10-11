#include<iostream>
using namespace std;

class kadane
{
public:
  int A[9]={1,2,7,-4,3,2,-10,9,1};
  int n=9;

public:
  
     void kadanes();  
};

void kadane::kadanes()
{  
    int i,max=A[0],sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+A[i];
        if(sum>max)
        max=sum;
        if(sum<0)
        sum=0;
    }
    cout<<"Maximum subarray sum from the given list is: "<<max;
}


int main()
{
    kadane K;
    K.kadanes();
    return 0;
}
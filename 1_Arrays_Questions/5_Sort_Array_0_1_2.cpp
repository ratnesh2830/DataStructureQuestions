#include<iostream>
using namespace std;

class Sort
{
    public:
    int A[8]={0,1,2,1,1,2,0,1};
    int n=8;
    public:
    void inPlaceSort();
};

void Sort::inPlaceSort()
{
    int i,count0,count1,count2;
    count0=count1=count2=0;
    for(i=0;i<n;i++)
    {
        if(A[i]==0)
        count0++;
        else if(A[i]==1)
        count1++;
        else if(A[i]==2)
        count2++;
    }

    for(i=0;i<n;i++)
    {
        if(count0!=0)
        { 
            A[i]=0;
            count0--;
        }
        else if(count1!=0)
        {
            A[i]=1;
            count1--;
        }
        else if(count2!=0)
        {
            A[i]=2;
            count2--;
        }
   
    }

for(i=0;i<n;i++)
{
    cout<<A[i]<<" ";
}
       
}

int main()
{
    Sort S;
    S.inPlaceSort();
return 0;
}
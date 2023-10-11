#include<iostream>
using namespace std;

class Stock
{
    public:
    int A[7]={7,6,4,3,1,0,12};
    int n=7;
    public:
    void Profit();
};

void Stock::Profit()
{
    int i,j,diff,x,y,profit=0;
    for(i=0;i<n;i++)
    {
        diff=0;
        for(j=i+1;j<n;j++)
        {
            diff=A[j]-A[i];
            if(diff>profit)
            {
                profit=diff;
                x=i;
                y=j;
            }
        }
    }
if(profit>0)
cout<<"The buying day is index "<<x<<" and the selling day is index "<<y<<" for maximum profit: "<<profit;
if(profit<=0)
cout<<"The buying day is index "<<x<<" and the selling day is index "<<y<<" with profit: "<<0;
}

int main()
{
    Stock S;
    S.Profit();
return 0;
}
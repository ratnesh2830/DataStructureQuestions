#include<iostream>
using namespace std;

class Stock
{
    public:
    int A[8]={7,1,5,3,6,4,0,12};
    int n=8;
    public:
    void Profit();
};

void Stock::Profit()
{
   int min=INT_MAX,profit=0,i,diff;

   for(i=0;i<n;i++)
   {
        if(A[i]<min)
        min=A[i];

        diff=A[i]-min;
        if(diff>profit)
        profit=diff;
   }

cout<<"maximum profit will be "<<profit;
}
int main()
{
    Stock S;
    S.Profit();
return 0;
}
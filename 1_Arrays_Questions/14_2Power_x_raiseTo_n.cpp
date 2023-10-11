#include<iostream>
using namespace std;

class Solution
{
    public:

    double power(float x,int n)
    {
        int nn=n;
        double result=1.0;
        if(n<0)
        nn=-1*nn;
        
        while(nn>0)
        {
            if(nn%2==1)
            {
                result=result*x;
                nn=nn-1;
            }
            else
            {
                x=x*x;
                nn=nn/2;
            }
        }

        if(n<0)
        result=1.0/result;
    
    return result;
    }
};

int main()
{
    Solution M;
    float value=2.0;
    int n=10;
    cout<<M.power(value,n);

return 0;
}
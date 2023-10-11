#include<iostream>
using namespace std;
class Solution
{
    public:

    double power(float value,long n)
    {
        double result=1;
        int nn=n;
        if(n<0)
        nn=-1*nn;
            
        for(int i=0;i<nn;i++)    
             {
                result=result*value;
             }
        
        if(n<0)
        result=1/result;
    
    return result;
    }
};

int main()
{
    Solution M;
    float value=2;
    long n=10;
    cout<<M.power(value,n);
return 0;
}
#include<iostream>
using namespace std;

class Solution
{
    public:

    double multiple(double mid,int n)
    {
        double res=1.0;
        for(int i=1;i<=n;i++)
        {
            res=res*mid;
        }
    return res;
    }

    double NthRoot(int n,int m)
    {
        double low=n;
        double high=m;
        double eps=1e-6;

        while(high-low>eps)
        {
           double mid=(high+low)/2.0;
            if(multiple(mid,n)>m)
            {
                high=mid;
            }
            else
            low=mid;
        }
    return low;
    }
};
int main()
{
    Solution M;
    int n=1;
    int m=27;
    double res=M.NthRoot(n,m);
    cout<<res;
return 0;
}
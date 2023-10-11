#include<iostream>
using namespace std;
#include<algorithm>

struct Train
{
    double  arri;
    double dep;
};

bool comparator(Train t1,Train t2)
{
    if(t1.arri<t2.arri)
    return true;
    
    else if(t1.arri>t2.arri)
    return false;
    
   return true;
}
class Solution
{
    public:

    int MinPlatform(double arri[],double dep[],int n)
    {
        Train t[n];
        for(int i=0;i<n;i++)
        {
            t[i].arri=arri[i];
            t[i].dep=dep[i];
        }
        sort(t,t+n,comparator);
         for(int i=0;i<n;i++)
        {
            cout<<t[i].arri<<" "<<t[i].dep<<endl;
        }
        int count=1;
        double lastdep=t[0].dep;
        int totalplatform=1;

        for(int i=1;i<n;i++)
        {
            if(t[i].arri>lastdep)
            {
                lastdep=t[i].dep;
                count=1;
            }
            else
            {
                count++;
                totalplatform=max(totalplatform,count);
            }
        }
    return totalplatform;
    }
};

int main()
{
    Solution M;
    double start[]={9.00,9.45,9.55,11.00,15.00,18.00};
    double dep[]={9.20,12.00,11.30,11.50,19.00,20.00};
    cout<<M.MinPlatform(start,dep,6);
return 0;
}
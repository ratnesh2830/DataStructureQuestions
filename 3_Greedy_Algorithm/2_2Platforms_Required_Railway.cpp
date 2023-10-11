#include<iostream>
using namespace std;

class Solution
{
    public:
    int TotalPlatforms(double arri[],double dep[],int n)
    {   
        int res=1;
        for(int i=0;i<n-1;i++)
        {
            int count=1;
            for(int j=i+1;j<n;j++)
            {
                if((arri[j]>arri[i]&&arri[j]<=dep[i])||(arri[j]<arri[i] && dep[j]>=arri[i]))
                    count++;

                res=max(res,count);
            }

        }
    return res;
    }
};

int main()
{
Solution M;
double arri[]={9.00,9.45,9.55,11.00,15.00,18.00};
    double dep[]={9.20,12.00,11.30,11.50,19.00,20.00};
cout<<M.TotalPlatforms(arri,dep,6);
return 0;
}
#include<iostream>
using namespace std;
#include<algorithm>
class Solution
{
    public:
    int TotalPlatforms(double arri[],double dep[],int n)
    {   
        int res=1;
        sort(arri,arri+n);
        sort(dep,dep+n);
        int i=0;
        int j=i+1;
        int count=1;
        while(i<n && j<n)
        {
            if(arri[j]<=dep[i])
                {count++;
                res=max(res,count);
                j++;
                }
            else
            {
            count--;
            i++;
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
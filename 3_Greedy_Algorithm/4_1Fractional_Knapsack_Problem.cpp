#include<iostream>
using namespace std;
#include<algorithm>
struct items
{
    int value;
    int weight;
};

bool comparator(items a,items b)
{
    double r1=(1.0)*a.value/a.weight;
    double r2=(1.0)*b.value/b.weight;
    if(r1>r2)
    return true;

return false;
}

class Solution
{
    public:
    int Maxitems(items A[],int n)
    {
        sort(A,A+n,comparator);
        int weight=10;
        double maxvalues=0;
        for(int i=0;i<n;i++)
        {
            if(weight!=0)
            {
                if(weight-A[i].weight>=0)
                {
                    maxvalues+=A[i].value;
                    weight-=A[i].weight;
                }
                else
                {
                    double a=A[i].value/(double)A[i].weight;
                    maxvalues+=a*weight;
                }
            }
            else
            break;
        }
    return maxvalues;
    }
};

int main()
{
    Solution M;
    items I[]={{500,30}};
    cout<<M.Maxitems(I,1);
return 0;
}
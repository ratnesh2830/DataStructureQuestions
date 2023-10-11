#include<iostream>
using namespace std;
#include<vector>

class Solution
{
    public:
    int Coins(int A[],int n,int V)
    {
        vector<int> res;
        for(int i=n-1;i>=0;i--)
        {
            while(A[i]<=V)
            {
                V=V-A[i];
                res.push_back(A[i]);
            }
        }
    
        for(int i=0;i<res.size();i++)
        {
            cout<<res[i]<<" ";
        }
        cout<<endl;
    return res.size();
    }
};

int main()
{
    Solution M;
    int A[]={1,2,5,10,20,50,100,500,1000};
    cout<<M.Coins(A,9,121);
return 0;
}
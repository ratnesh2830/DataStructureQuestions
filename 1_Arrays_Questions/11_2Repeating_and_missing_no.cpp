#include<iostream>
using namespace std;
#include<vector>

class Solution
{
    public:
    void RM(vector<int> &vec)
    {
        int a,b,i;
        for(i=0;i<vec.size();i++)
        {
            if(vec[abs(vec[i])-1]<0)
            a=abs(vec[i]);

            else
            vec[abs(vec[i])-1]=-vec[abs(vec[i])-1];
        }

        for(i=0;i<vec.size();i++)
        {
            if(vec[i]>0)
            b=i+1;
        }
    
    cout<<"repeating number is:"<<a<<endl;
    cout<<"missing number is: "<<b<<endl;
    }
};

int main()
{
    Solution M;
    vector<int> vec{1,4,2,5,6,5,7};
    M.RM(vec);
return 0;
}
//In this program we have to find 2 numbers from the range one is the repeating number and second one is the missing number
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Solution
{
    public:

    void repeating_missing(vector<int> &vec)
    {
        int i,a,b;
        sort(vec.begin(),vec.end());
        for(i=0;i<vec.size()-1;i++)
        {
                if(vec[i]==vec[i+1])
                {
                    a=vec[i];
                }
                else if(vec[i]=vec[i+1]-2)
                {
                    b=vec[i]+1;
                }
        }
    cout<<"repeating number is:"<<a<<endl;
    cout<<"missing number is: "<<b;
    }
};

int main()
{
    Solution M;
    vector<int> vec{3,1,2,5,3};
    M.repeating_missing(vec);
return 0;
}
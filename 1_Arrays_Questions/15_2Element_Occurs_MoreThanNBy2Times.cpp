#include<iostream>
#include<vector>
using namespace std;

class Solution
{
    public:
    int MooreA(vector<int> &vec)
    {
        int count=0;
        int ele=0;
        for(int i=0;i<vec.size();i++)
        {
            if(count==0)
            {
                ele=vec[i];
            }
            if(ele==vec[i])
            {
                count++;
            }
            else
            count--;
        }
    if(count==0)
    return 0;

    return ele;
    }
};

int main()
{
    Solution M;
    vector<int> vec{3,3,1,1,3,3,3,4};
    cout<<M.MooreA(vec);
return 0;
}
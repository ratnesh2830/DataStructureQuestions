#include<iostream>
using namespace std;
#include<vector>

class Solution
{
    public:

    int Inversion(vector<int> &vec)
    {
        int i,j,count=0;
        for(i=0;i<vec.size();i++)
        {
            for(j=i+1;j<vec.size();j++)
            {
                if(vec[i]>vec[j])
                {
                    count++;
                }
            }
        }
    return count;
    }
};

int main()
{
    Solution M;
    vector<int> vec{5,4,3,2,1};
    cout<<M.Inversion(vec);
return 0;
}
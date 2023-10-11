#include<iostream>
#include<vector>
using namespace std;

class Solution
{
    public:
    int SearchSingle(vector<int>&vec)
    {
        int ele=0;
        for(int i=0;i<vec.size();i++)
        {
            ele=ele^vec[i];
        }
    return ele;
    }
};

int main()
{
    vector<int>vec{1,1,2,3,3,4,4,5,5};
    Solution M;
    cout<<M.SearchSingle(vec);
return 0;
}
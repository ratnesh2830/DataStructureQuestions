#include<iostream>
using namespace std;
#include<vector>

class Solution
{
    public:

    int Dublicate(vector<int> &vec)
    {
        int slow,fast;
        slow=vec[0];
        fast=vec[0];

        do
        {
            slow=vec[slow];
            fast=vec[vec[fast]];
        }while(slow!=fast);

        fast=vec[0];
        while(slow!=fast)
        {
            slow=vec[slow];
            fast=vec[fast];
        }
    return slow;               
}
};

int main()
{
    vector<int> vec{1,2,3,6,5,4,6};
    Solution M;
    cout<<M.Dublicate(vec);

return 0;
}

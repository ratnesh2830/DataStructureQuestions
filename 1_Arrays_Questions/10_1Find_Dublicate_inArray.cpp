//in this program we are going to find the one number which is repeated either one or maximum time in the given array
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Solution
{
    public:

    int Dublicate(vector<int> &vec)
    {
        int i,a;
        sort(vec.begin(),vec.end());
        
        for(i=0;i<vec.size()-1;i++)
        {
            if(vec[i]==vec[i+1])
            {
                a=vec[i];
                 break;
            }
       
        }
    return a;
    }
};

int main()
{
    Solution M;
    vector<int> vec{1,2,3,4,5,6,2};
    cout<<M.Dublicate(vec);

return 0;
}
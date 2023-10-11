#include<iostream>
using namespace std;
#include<vector>

class Solution
{
    public:
    int Xor(vector<int> &vec,int b)
    {   
        int count=0;
        int Xor=0;
        if(vec.empty())
        return 0;

        for(int i=0;i<vec.size();i++)
        {
            Xor=0;
            for(int j=i;j<vec.size();j++)
            {
                Xor=Xor ^ vec[j];
                if(Xor==b)
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
    vector<int> vec{5, 6, 7, 8, 9};
    int b=5;
    cout<<M.Xor(vec,b);
return 0;
}
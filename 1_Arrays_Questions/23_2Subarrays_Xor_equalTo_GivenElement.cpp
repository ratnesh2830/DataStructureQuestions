#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>

class Solution
{
    public:
    int Xor(vector<int> &vec,int b)
    {
        unordered_map<int,int> hashmap;
        int Xor=0;
        int count=0;
        if(vec.empty())
        return 0;

        for(int i=0;i<vec.size();i++)
        {   
            Xor=Xor^vec[i];
            if(Xor==b)
            count++;

            if(hashmap.find(Xor^b)!=hashmap.end())
            {
                count+=hashmap[Xor^b];
            }

            hashmap[Xor]+=1;
        }
    return count;
    }
};

int main()
{
    Solution M;
    vector<int> vec{5, 6, 7, 8, 9};
    int b=5;
    cout<<M.Xor(vec,6);
return 0;
}
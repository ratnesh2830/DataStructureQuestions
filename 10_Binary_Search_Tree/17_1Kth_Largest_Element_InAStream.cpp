#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class kthlargestelement
{
    vector<int>vec;
    int k;

    public:
    kthlargestelement(int k,vector<int>&num)
    {
        this->k=k;
        for(int i=0;i<num.size();i++)
        {
            vec.push_back(num[i]);
        }
    }

    int add(int x)
    {
        vec.push_back(x);
        sort(vec.begin(),vec.end(),greater<int>());
        return vec[k-1];
    }
};

int main()
{
    vector<int>num={7,5,4,9,10};
    kthlargestelement M(3,num);
    cout<<M.add(21)<<endl;
    cout<<M.add(25);

return 0; 
}
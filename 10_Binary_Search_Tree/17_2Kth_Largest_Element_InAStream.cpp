#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<algorithm>

class kthlargestelement
{
    priority_queue<int,vector<int>,greater<int>>pq;
    int k;

    public:
    kthlargestelement(int k,vector<int>&num)
    {
        this->k=k;
        for(int i=0;i<num.size();i++)
        {
            pq.push(num[i]);
            if(pq.size()>k)
            pq.pop();
        }
    }

    int add(int x)
    {
        pq.push(x);
        if(pq.size()>k)
        pq.pop();

    return pq.top();
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
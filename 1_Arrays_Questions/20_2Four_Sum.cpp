#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Solution
{
    public:
    vector<vector<int>> FourSum(vector<int> &vec,int target)
    {
        vector<vector<int>> res;
        int i,j,k,x,twoSum;

        if(vec.empty())
        return res;
        sort(vec.begin(),vec.end());
        for(i=0;i<vec.size();i++)
        {
            for(j=i+1;j<vec.size();j++)
            {
                int front=j+1;
                int back=vec.size()-1;
                x=target-vec[i]-vec[j];
                while(front<back)
                    {
                        twoSum=vec[front]+vec[back];

                        if(twoSum<x)
                        front++;

                        else if(twoSum>x)
                        back--;

                        else
                        {
                            vector<int>v(4,0);
                            v[0]=vec[i];
                            v[1]=vec[j];
                            v[2]=vec[front];
                            v[3]=vec[back];
                            res.push_back(v);
                        
                        while(front<back && vec[front]==v[2])
                        front++;

                        while(front<back && vec[back]==v[3])
                        back--;
                        }
                    }
            
            while(j<vec.size() && vec[j]==vec[j+1])
            j++;
            
            }
        while(i<vec.size() && vec[i]==vec[i+1])
        i++;
        }
    return res;
    }
};

int main()
{
    Solution M;
    vector<int> vec{4,4,4,3,3,2,2,1,1,1};
    int target = 9;
    vector<vector<int>> res;
    res=M.FourSum(vec,target);

    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            cout<<res[i][j]<<" ";
        }
    cout<<endl;
    }
return 0;

}
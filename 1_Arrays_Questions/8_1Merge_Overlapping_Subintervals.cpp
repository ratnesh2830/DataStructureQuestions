#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class solution
{
public:
vector<pair<int,int>> Merge(vector<pair<int,int>>vec)
{
    vector<pair<int,int>>result;
    int k=0;
    if(vec.empty() || (vec[0].first && vec[0].second)==0 )
    {
        return result;
    }
    sort(vec.begin(),vec.end());
    for(int i=0;i<vec.size();i++)
    {
        if(result.empty())
        {
            result.push_back(vec[i]);
        }
        else
        {
            if(result[k].second>=vec[i].second)
            {
                continue;
            }
            else
            {
                result.push_back(vec[i]);
                k++;
            }
        }

        for(int j=i+1;j<vec.size();j++)
        {
            if(result[k].second>=vec[j].first)
            {
                result[k].second=max(result[k].second,vec[j].second);
            }
            
        }
    }
return result;
}
};


int main()
{
    solution M;
    vector<pair<int,int>>vec{{8,9},{1,3},{2,6},{9,9},{15,18},{2,4}};
    vector<pair<int,int>>result;
    result=M.Merge(vec);

    if(!result.empty())
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i].first<<" "<<result[i].second<<endl;
    }
    else
    cout<<"given interval is not valid";
    

return 0;
}
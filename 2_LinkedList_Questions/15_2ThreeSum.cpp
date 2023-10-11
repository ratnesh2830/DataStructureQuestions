#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<set>

class Solution
{
    public:
    vector<vector<int>> ThreeSum(vector<int> &vec)
    {
      set<vector<int>>set;

      sort(vec.begin(),vec.end());

      for(int i=0;i<vec.size()-2;i++)
      {
        int j=i+1;
        int k=vec.size()-1;
        while(j<k)
        {
            int twosum=vec[j]+vec[k];
            if(twosum+vec[i]==0)
            {
                vector<int> vec1;
                vec1.push_back(vec[i]);
                vec1.push_back(vec[j]);
                vec1.push_back(vec[k]);
                set.insert(vec1);
                j++;k++;

            
            }
            else if(twosum+vec[i]<0)
            j++;
            else
            k--;
        }
      }
    vector<vector<int>> res(set.begin(),set.end());
    return res;
    }
};

int main()
{
Solution M;
vector<int> vec{-1,0,1,2,-1,-4};
vector<vector<int>> res;
res=M.ThreeSum(vec);
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
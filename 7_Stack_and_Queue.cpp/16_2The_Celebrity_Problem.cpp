#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution
{
    public:
    int CelebrityProblem(vector<vector<int>>&vec)
    {
        stack<int>stack;
        int n=vec.size();
        int check1,check2,row;
        for(int i=0;i<n;i++)
        {
            stack.push(i);
        }

        while(stack.size()>1)
        {
            check1=stack.top();
            stack.pop();
            check2=stack.top();
            stack.pop();

            if(vec[check1][check2]==0 && vec[check2][check1]==0)
            continue;
            else if(vec[check1][check2]==1)
            {
                stack.push(check2);
            }
            else
            {
                stack.push(check1);
            }
        }

        if(stack.empty()==true)
        return -1;
        else
        {
            row=stack.top();
            for(int i=0;i<n;i++)
            {
                if(i==row)
                continue;

                if(vec[i][row]==0)
                return -1;

                if(vec[row][i]==1)
                return -1;
            }
        }
    
    return row;
            
    }
};

int main()
{
    Solution M;
    vector<vector<int>>vec={{0, 0, 1, 0},
                            {0, 0, 1, 0},
                            {0, 1, 0, 0},
                            {0, 0, 1, 0},};
    cout<<M.CelebrityProblem(vec);
return 0;
}

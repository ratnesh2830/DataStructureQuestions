#include<iostream>
#include<vector>
using namespace std;

class Solution
{
    public:
    void function(int col,vector<string>&board,vector<vector<string>>&res,vector<int>&leftrow,vector<int>&lowerdiag,vector<int>&upperdiag)
    {
        if(col==board.size())
        {
            res.push_back(board);
            return;
        }

        for(int row=0;row<board.size();row++)
        {
            if(leftrow[row]==0 && lowerdiag[row+col]==0 && upperdiag[(board.size()-1)+(col-row)]==0)
            {
                board[row][col]='Q';
                leftrow[row]=1;
                lowerdiag[row+col]=1;
                upperdiag[board.size()-1+(col-row)]=1;
                function(col+1,board,res,leftrow,lowerdiag,upperdiag);
                board[row][col]='.';
                leftrow[row]=0;
                lowerdiag[row+col]=0;
                upperdiag[board.size()-1+(col-row)]=0;
            }
        }
    }
    vector<vector<string>>Nqueen(int n)
    {
        vector<vector<string>>res;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<board.size();i++)
        {
            board[i]=s;
        }
        vector<int>leftrow(n,0);
        vector<int>lowerdiag((2*n)-1,0);
        vector<int>upperdiag((2*n)-1,0);
        int col=0;
        function(col,board,res,leftrow,lowerdiag,upperdiag);
    return res;
    }
};

int main()
{
    Solution M;
    vector<vector<string>>res;
    res=M.Nqueen(4);
    for(int i=0;i<res.size();i++)
    {
        cout<<"arrangement"<<i+1<<endl;
        for(int j=0;j<res[i].size();j++)
        {
            cout<<res[i][j]<<endl;
        }
    cout<<endl;
    }
return 0;
}
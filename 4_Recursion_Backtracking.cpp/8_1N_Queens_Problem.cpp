#include<iostream>
using namespace std;
#include <vector>

class Solution
{
    public:
    bool isSafe(vector<string>&board,int row,int col)
    {
        int newrow=row;
        int newcol=col;

        while(row>=0 && col>=0)
        {
            if(board[row][col]=='Q')
            return false;

            row--;
            col--;
        }
    row=newrow;
    col=newcol;

        while(col>=0)
        {
            if(board[row][col]=='Q')
            return false;

            col--;
        }
    
    col=newcol;
        while(row<board.size() &&col>=0)
        {
            if(board[row][col]=='Q')
            return false;

            row++;
            col--;
        }

    return true;
    }

    void function(int col,vector<string>&board,vector<vector<string>>&res)
    {
        if(col==board.size())
        {
            res.push_back(board);
            return ;
        }

        for(int row=0;row<board.size();row++)
        {
            if(isSafe(board,row,col))
            {
                board[row][col]='Q';
                function(col+1,board,res);
                board[row][col]='.';
            }
        }


    }

    vector<vector<string>> Nqueen(int n)
    {
        vector<vector<string>>res;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }

        function(0,board,res);

    return res;
    }
};

int main() 
{
  int n = 4; // we are taking 4*4 grid and 4 queens
  Solution obj;
  vector < vector < string >> ans = obj.Nqueen(n);
  for (int i = 0; i < ans.size(); i++) {
    cout << "Arrangement " << i + 1 << "\n";
    for (int j = 0; j < ans[i].size(); j++) {
      cout << ans[i][j];
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}
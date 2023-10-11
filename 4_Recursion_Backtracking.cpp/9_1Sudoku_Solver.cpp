#include<iostream>
#include<vector>
using namespace std;
class Solution
{
    public:
    bool IsSafe(vector<vector<char>>board,char c,int row,int col)
    {
        for(int i=0;i<board.size();i++)
        {
            if(board[row][i]==c)
            return false;

            if(board[i][col]==c)
            return false;

            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c)
            return false;
        }
    return true;
    }  

    bool Function(vector<vector<char>>&board)
    {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]=='.')
                {
                    for(char c='1';c<='9';c++)
                    {
                        if(IsSafe(board,c,i,j))
                        {
                            board[i][j]=c;
                            if(Function(board)==true)
                            return true;
                            else
                            board[i][j]='.';
                        }
                    }
                return false;
                }
            }
        }
    return true;
    }

    void SudokuSolver(vector<vector<char>>&board)
    {
        Function(board);
    }
};

int main()
{
    Solution M;
    vector<vector<char>>board{
        {'9', '5', '7', '.', '1', '3', '.', '8', '4'},
        {'4', '8', '3', '.', '5', '7', '1', '.', '6'},
        {'.', '1', '2', '.', '4', '9', '5', '3', '7'},
        {'1', '7', '.', '3', '.', '4', '9', '.', '2'},
        {'5', '.', '4', '9', '7', '.', '3', '6', '.'},
        {'3', '.', '9', '5', '.', '8', '7', '.', '1'},
        {'8', '4', '5', '7', '9', '.', '6', '1', '3'},
        {'.', '9', '1', '.', '3', '6', '.', '7', '5'},
        {'7', '.', '6', '1', '8', '5', '4', '.', '9'}};
    M.SudokuSolver(board);

    for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
return 0;
}

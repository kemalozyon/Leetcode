#include <iostream>
#include <set>

using namespace std;

class Solution
{
public:
    const int ROW = 9;
    const int COLUMN = 9;
    bool isValidSudoku(vector<vector<char>> &board)
    {
        set<int> mySet;
        int n = board.size();
        // Checking the rows
        for (int i = 0; i < ROW; i++)
        {
            for (int j = 0; j < COLUMN; j++)
            {
                if (board[i][j] != '.')
                {
                    if (mySet.count(board[i][j] - '0'))
                    {
                        return false;
                    }
                    mySet.insert(board[i][j] - '0');
                }
            }
            mySet = {};
        }
        mySet = {};
        // checking the columns:
        for (int i = 0; i < COLUMN; i++)
        {
            for (int j = 0; j < ROW; j++)
            {
                if (board[j][i] != '.')
                {
                    if (mySet.count(board[j][i] - '0'))
                    {
                        return false;
                    }
                    mySet.insert(board[j][i] - '0');
                }
            }
            mySet = {};
        }
        mySet = {};
        vector<vector<int>> myData(9);
        // Preparing the data
        for (int i = 0; i < ROW; i++)
        {
            for (int j = 0; j < COLUMN; j++)
            {
                if (board[i][j] != '.')
                {
                    if (j < 3)
                    {
                        if (i < 3)
                        {
                            myData[0].push_back(board[i][j] - '0');
                        }
                        else if (i < 6)
                        {
                            myData[3].push_back(board[i][j] - '0');
                        }
                        else
                        {
                            myData[6].push_back(board[i][j] - '0');
                        }
                    }
                    else if (j < 6)
                    {
                        if (i < 3)
                        {
                            myData[1].push_back(board[i][j] - '0');
                        }
                        else if (i < 6)
                        {
                            myData[4].push_back(board[i][j] - '0');
                        }
                        else
                        {
                            myData[7].push_back(board[i][j] - '0');
                        }
                    }
                    else
                    {
                        if (i < 3)
                        {
                            myData[2].push_back(board[i][j] - '0');
                        }
                        else if (i < 6)
                        {
                            myData[5].push_back(board[i][j] - '0');
                        }
                        else
                        {
                            myData[8].push_back(board[i][j] - '0');
                        }
                    }
                }
            }
        }

        for (int i = 0; i < 9; i++)
        {
            int n = myData[i].size();
            for (int j = 0; j < n; j++)
            {
                if (mySet.count(myData[i][j]))
                {
                    return false;
                }
                mySet.insert(myData[i][j]);
            }
            mySet = {};
        }
        return true;
    }
};

int main(void)
{
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    Solution sol;
    bool value = sol.isValidSudoku(board);
    cout << value;
}

#include <iostream>
#include <vector>
#include <unordered_set> // Does not contain duplicates and it stores = {1,2,3,4,5,1,2,3,12}
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {

        vector<unordered_set<char>> row_s(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> grid(9);
        // Rows
        for (int i = 0; i < 9; i++)
        {
            // Redeclare
            for (int j = 0; j < 9; j++)
            {

                if (row_s[i].find(board[i][j]) != row_s[i].end() && board[i][j] != '.')
                {
                    return false; // We found a duplicate
                }
                row_s[i].insert(board[i][j]);
                if (cols[i].find(board[j][i]) != cols[i].end() && board[j][i] != '.')
                {
                    return false; // We found a duplicate
                }
                cols[i].insert(board[j][i]);
                int index = (i / 3) * 3 + j / 3;
                if (grid[index].find(board[i][j]) != grid[index].end() && board[i][j] != '.')
                {
                    return false;
                }
                grid[index].insert(board[i][j]);
            }
        }

        // int index = (rows /3) * 3 + col / 3
        return true;
    } // End of function
};

// Test cases:

int main()
{
    // Test Case
    vector<vector<char>> board = {{'5', '0', '.', '.', '7', '.', '.', '.', '.'},
                                  {'6', '.', '.', '1', '9', '5', '0', '.', '.'},
                                  {'0', '9', '8', '.', '.', '.', '.', '6', '.'},
                                  {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                  {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                  {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                  {'1', '6', '.', '.', '.', '.', '2', '8', '.'},
                                  {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                  {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    Solution sol;
    bool result = sol.isValidSudoku(board);
    cout << result;
}
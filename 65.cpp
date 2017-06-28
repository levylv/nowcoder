#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if (matrix == NULL || str == NULL)
            return false;
        int sum = rows * cols;
        int row, col;
        vector<vector<int> > gone(rows, vector<int> (cols, 0));
        for (int i = 0; i < sum; i++)
        {
            row = i / cols;
            col = i % cols;
            if (Path(matrix, rows, cols, str, row, col, gone))
            {
                return true;
            }
        }
        return false;
    
    }

    bool Path(char* matrix, int num_rows, int num_cols, char* str, int row, int col, vector<vector<int> > gone)
    {
        if (*str == '\0')
            return true;
        if (row < 0 || row >= num_rows || col < 0 || col >= num_cols)
            return false;
        if (*(matrix + row * num_cols + col) != *str)
            return false;
        else if (gone[row][col] == 1)
            return false;
        else
        {
            gone[row][col] = 1;
            return Path(matrix, num_rows, num_cols, str+1, row+1, col, gone) ||Path(matrix, num_rows, num_cols, str+1, row-1, col, gone) || Path(matrix, num_rows, num_cols, str+1, row, col+1, gone) || Path(matrix, num_rows, num_cols, str+1, row, col-1, gone);

        }

    }
};

int main()
{
    Solution sol;
    char matrix[] = "ABCESFCSADEE";
    char str[] = "ABCCED";
    cout << sol.hasPath(matrix, 3, 4, str) << endl; 
}

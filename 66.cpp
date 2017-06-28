#include <iostream>
using namespace std;

class Solution {
public:
    int count = 0;
    int movingCount(int threshold, int rows, int cols)
    {
        if (threshold <= 0 || rows <= 0 || cols <= 0)
            return 0;
        vector<vector<int> > grid(rows, vector<int>(cols, 0));
        GridRule(threshold, rows, cols, 0, 0, grid);
        return count;
    }

    int DigitSum(int x)
    {
        int sum = 0;
        while (x > 0)
        {
            sum += x % 10;
            x = x / 10;
        }
        return sum;
    }

    void GridRule(int threshold, int rows, int cols, int row, int col, vector<vector<int> > &grid)
    {
        if (row < 0 || row >= rows || col < 0 || col >= cols)
            return;
        if (DigitSum(row) + DigitSum(col) <= threshold && grid[row][col] == 0)
        {
            count++;
            grid[row][col] = 1;
            GridRule(threshold, rows, cols, row+1, col, grid);
            GridRule(threshold, rows, cols, row-1, col, grid);
            GridRule(threshold, rows, cols, row, col+1, grid);
            GridRule(threshold, rows, cols, row, col-1, grid);
        }
    }
};


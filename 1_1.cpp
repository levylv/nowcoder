class Solution{
Public:
    bool Find(int target, vector<vector<int>> array)
    {
        int Bound = array[0].size() - 1;
        int i=0, j=0;
        while (true)
        {
            if (Bound < 0)
            {
                return false;
            }
            if (i == array.size())
            {
                return false;
            }
            if (j == 0 && target < array[i][j])
            {
                return false;
            }
            if (target == array[i][j])
            {
                return true;
            }
            else if (target > array[i][j] && j != Bound)
            {
                j++;
            }
            else if (target > array[i][j] && j == Bound)
            {
                i++;
                j = 0;
            }
            else
            {
                Bound = j -1;
                i++;
                j = 0;
            }

        }
    }
}

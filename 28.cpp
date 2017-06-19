class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int count = 1;
        int num = numbers[0];
        for (int i=1;i<numbers.size();i++)
        {
            if (count == 0)
                count = 1;
            if (num != numbers[i])
                count--;
            else count++;
            if (count == 0)
            {
                num = numbers[i];
            }
        }
        if (count <= 0)
            return 0;
        else return num;
    }
};

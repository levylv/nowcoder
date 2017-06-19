class Solution{
public:
    int jumpFloorII(int number)
    {
        vector<int> record(number+1);
        record[0] = 1;
        record[1] = 1;
        record[2] = 2;
        for (int i=3;i<=number;i++)
        {
            for (int j = 0;j<i;j++)
            {
                record[i] += record[j];
            }
        }
        return record[number];
    }

};

#其实递推一下就能得到闭式解

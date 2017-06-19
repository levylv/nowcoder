#该题还是fibonacci数列
class Solution {
public:
    int rectCover(int number) {
        vector<int> record(number+1);
        record[0] = 1;
        record[1] = 2;
        for (int i = 2;i<number;i++)
        {
            record[i] = record[i-1] + record[i-2];
        }
        return record[number-1];

    }
};

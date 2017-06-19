#递归, 610ms 8568K class Solution{
public:
    int jumpFloor(int number){
        if (number == 1)
        {
            return 1;
        }
        else if (number == 2)
        {
            return 2;
        }
        else
        {
            return jumpFloor(number - 1) + jumpFloor(number - 2);
        }
    }

};

#动归, <1ms, 8552K
class Solution{
public:
    int jumpFloor(int number){
        vector<int> record(number, 0);
        if (number == 1)
        {
            return 1;
        }
        else if (number == 2)
        {
            return 2;
        }
        else
        {
            record[0] = 1;
            record[1] = 2;
            for (int i=2;i<number;i++)
            {
                record[i] = record[i-1] + record[i-2];
            }
            return record[number-1];
        }
    }

};


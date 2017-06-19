class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        string res;
        int temp;
        for (size_t i = 0; i < numbers.size(); i++)
        {
            for (size_t j = numbers.size()-1; j > i; j--)
            {
                if (compare(numbers[j], numbers[j-1]))
                {
                    temp = numbers[j];
                    numbers[j] = numbers[j-1];
                    numbers[j-1] = temp;
                }
            }
            res += to_string(numbers[i]);
        }
        return res;
    }

    bool compare(int m, int n)
    {
        string str1 = to_string(m) + to_string(n);
        string str2 = to_string(n) + to_string(m);
        int len = str1.size();
        for (int i = 0; i < len; i++)
        {
            if (str1[i] == str2[i])
                continue;
            else if (str1[i] < str2[i])
                return true;
            else
                return false;
        }
        return true;
    }
};

class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if (numbers.empty())
            return false;
        int len = numbers.size();
        sort(numbers.begin(), numbers.end(), compare);
        int number_zero = 0;
        for (int i = 0; i < len && numbers[i] == 0; i++)
        {
                number_zero++;
        }
        int number_gap = 0;
        int small = number_zero;
        int big = small + 1;
        while (big < len)
        {
            if (numbers[big] == numbers[small])
                return false;
            number_gap += numbers[big] - numbers[small] - 1;
            small++;
            big++;
        }
        return (number_gap > number_zero)? false: true;
    }

    static bool compare(const int a, const int b)
    {
        return (a < b);
    }
};

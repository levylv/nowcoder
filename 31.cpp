class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int count = 0;
        int i = 1;
        for (i; i <= n; i*=10)
        {
            int a = n / i, b = n % i;
            count += (a+8) / 10 * i;
            if (a%10 == 1)
                count += b+1;
        }
        return count;
    }
};

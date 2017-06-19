class Solution{
public:
    int Fibonacci(int n){
        int first = 0;
        int second = 1;
        int sum = 0;
        if (n == 1)
        {
            return 1;
            
        }
        for (int i=0;i<n-1;i++)
        {
            sum = first + second;
            first = second;
            second = sum;
        }
        return sum;
    }
};

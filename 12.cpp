//复杂度O(n)
class Solution {
public:
    double Power(double base, int exponent) {
        int res = 1;
        int a = abs(exponent);
        while (a--)
        {
            res *= base; 
        }
        return exponent>0?res:1.0 / res;
    
    }
};

//复杂度O(log(n))
class Solution {
public:
    double Power(double base, int exponent) {
        int res = 1;
        int a = abs(exponent);
        while(a)
        {
            if (a&1)
            {
                res *= base;
            }
            base *= base;
            a >>= 1;
        }
        return exponent>0?res:1.0 / res;
    
    }
};




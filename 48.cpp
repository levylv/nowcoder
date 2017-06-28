#include <iostream>
using namespace std;

class Solution {
public:
    int Add(int num1, int num2)
    {
        int sum = num1 ^ num2;
        int carry = (num1 & num2) << 1;
        int temp;
        while (carry != 0)
        {
            temp = sum ^ carry;
            carry = (sum & carry) << 1;
            sum = temp;
        }
        return sum;

    }
};

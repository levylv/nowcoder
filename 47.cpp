#include <iostream>
using namespace std;

class Solution {
public:
    int Sum_Solution(int n) {
        int ans = n;
        ans && (ans += Sum_Solution(n-1) + n);
        return ans;
    }
};

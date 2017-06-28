#include <iostream>
using namespace std;

class Solution {
public:
    string LeftRotateString(string str, int n) {
        if (str.empty())
            return str;
        int len = str.size();
        n %= len;
        str.append(str.begin(), str.begin() + n);
        str.erase(0, n);
        return str;
        
    }
};

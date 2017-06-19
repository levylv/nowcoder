#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if (index <= 0) return 0;
        vector<int> res;
        res.push_back(1);
        int i, min;
        int index2 = 0, index3 = 0, index5 = 0;
        for (i = 1; i < index; i++)
        {
            min = res[index2] * 2;
            if (res[index3] * 3 < min)
                min = res[index3] * 3;
            if (res[index5] * 5 < min)
                min = res[index5] * 5;
            res.push_back(min);
            while (res[index2] * 2 <= res[i])
                index2++;
            while (res[index3] * 3 <= res[i])
                index3++;
            while (res[index5] * 5 <= res[i])
                index5++;
        }
        return res[index-1];
    
    }
};

int main()
{
    Solution sol;
    cout << sol.GetUglyNumber_Solution(1000) << endl;
}

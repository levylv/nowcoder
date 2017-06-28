#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        int k;
        int x;
        vector<vector<int>> v;
        vector<int> temp;
        for (k = sum; k >= 2; k--)
        {
            if (((2 * sum - k * (k - 1)) % (2 * k)) == 0)
            {
                x = (2 * sum - k * (k - 1)) / (2 * k);
                if (x > 0)
                {
                    for (int i = x; i < x+k; i++)
                    {
                        temp.push_back(i);
                    }
                    v.push_back(temp);
                    temp.clear();
                }
            }
        }
        return v;
        
    }
};

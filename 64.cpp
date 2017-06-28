#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        int len = num.size();
        vector<int> res;
        if (len < size || size <= 0)
            return res;
        deque<int> index;
        index.push_back(0);
        for (int i = 1; i < size; i++)
        {
            while (!index.empty() && num[i] >= num[index.back()])
                index.pop_back();
            index.push_back(i);
        }
        for (int i = size; i < len; i++)
        {
            res.push_back(num[index.front()]);
            if (index.front() + size > i)
            {
                while (!index.empty() && num[i] >= num[index.back()])
                    index.pop_back();
                index.push_back(i);
            }
            else
            {
                index.pop_front();
                while (!index.empty() && num[i] >= num[index.back()])
                    index.pop_back();
                index.push_back(i);
            }
        }
        res.push_back(num[index.front()]);
        return res;
    }
};

#include <iostream>
using namespace std;

class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        vector<int> child;
        int pos = 0;
        for (int i = 0; i < n; i++)
        {
            child.push_back(i);
        }
        while (child.size()>1)
        {
            pos = (pos + m - 1) % child.size();
            child.erase(child.begin()+pos);
        }
        return child[0];
        
    }
};

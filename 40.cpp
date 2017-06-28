#include <iostream>
using namespace std;

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int sum = 0;
        for (int i = 0;i < data.size(); i++)
        {
            sum ^= data[i];
        }
        int count = 0;
        while ((sum | (1<<count)) != sum)
            count++;
        vector<int> v1, v2;
        for (int i = 0; i< data.size(); i++)
        {
            if ((data[i] | (1<<count)) == data[i])
                v1.push_back(data[i]);
            else
                v2.push_back(data[i]);
        }
        for (int i = 0; i < v1.size(); i++)
        {
            *num1 ^= v1[i];
        }
        for (int i = 0; i < v2.size(); i++)
        {
            *num2 ^= v2[i];
        }
    }
};

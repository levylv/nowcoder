#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> B, C, D;
        if (A.size() <= 1)
            return B;
        int sum = 1;
        C.push_back(sum);
        for (int i = 1; i < A.size(); i++)
        {
            sum *= A[i-1];
            C.push_back(sum);
        }
        sum = 1;
        D.push_back(sum);
        for (int i = A.size()-1; i >= 1; i--)
        {
            sum *= A[i];
            D.push_back(sum);
        }
        for (int i = 0; i < A.size(); i++)
        {
            B.push_back(C[i] * D[A.size()-1-i]);
        }
        return B;
    
    }
};

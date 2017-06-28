#include <iostream>
using namespace std;

class Solution {
public:
    string ReverseSentence(string str) {
        if (str.empty())
            return str;
        Reverse(str.begin(), str.end() - 1);
        string::iterator left = str.begin();
        string::iterator right = str.begin();
        for (string::iterator it = str.begin(); it != str.end(); it++)
        {
            if (*it == ' ' && it != str.end()-1)
            {
                right = it-1;
                Reverse(left, right);
                left = it+1;
            }
        }
        if (str[str.size()-1] == ' ')
        {
            right = str.end()-2;
            Reverse(left, right);
            return str;
        }
        else
        {
            right = str.end()-1;
            Reverse(left, right);
            return str;
        }
    }

    void Reverse(string::iterator left, string::iterator right)
    {
        char temp;
        while (left <= right)
        {
            temp = *left;
            *left = *right;
            *right = temp;
            left++;
            right--;
        }
    }
};

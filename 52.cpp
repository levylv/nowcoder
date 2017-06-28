#include <iostream>
using namespace std;

class Solution {
public:
    bool match(char* str, char* pattern)
    {
        if (*str =='\0')
        {
            if (*pattern == '\0')
                return true;
            else if (*(pattern+1) != '*')
                return false;
            else
                return match(str, pattern+2);
        }
        else
        {
            if (*pattern == '\0')
            {
                return false;
            }
            else 
            {
                if (*(pattern+1) != '*')
                {
                    if (*pattern == '.' || (*pattern == *str))
                        return match(++str, ++pattern);
                    else
                        return false;
                }
                else
                {
                    if (*pattern == '.' || (*pattern == *str))
                    {
                        return match(str+1, pattern) || match(str, pattern+2) || match(str+1, pattern+2);
                    }
                    else
                    {
                        return match(str, pattern+2);
                    }
                }

            }
        }
    
    }
};

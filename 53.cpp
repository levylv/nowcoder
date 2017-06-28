#include <iostream>
using namespace std;

class Solution {
public:
    bool isNumeric(char* string)
    {
        if (string == NULL || *string == '\0')
            return false;
        if (*string == '+' || *string == '-')
            string++;
        bool flag = true;
        scanInteger(&string);
        if (*string != '\0')
        {
            if (*string == '.')
            {
                string++;
                scanInteger(&string);
                if (*string == 'e' || *string == 'E')
                    flag = isExponential(&string); 
                if (*string != '\0')
                    flag = false;
            }
            else if (*string == 'e' || *string == 'E')
            {
                flag = isExponential(&string);
            }
            else
                flag = false;
        }
        return flag;
    }

    void scanInteger(char** string)
    {
        while (**string != '\0' && **string <= '9' && **string >= '0')
            (*string)++;
    }

    bool isExponential(char** string)
    {
        (*string)++;
        if (**string == '+' || **string == '-')
            (*string)++;
        if (**string == '\0')
            return false;
        scanInteger(string);
        return (**string  == '\0')? true: false;
    }

};

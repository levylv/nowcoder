class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if (str.size() == 0) return -1;
        vector<int> letter(256);
        for (int i = 0; i < str.size(); i++)
        {
            letter[str[i]]++;
        }
        for (int i = 0; i < str.size(); i++)
        {
            if (letter[str[i]] == 1)
                return i;
        }
        return -1;
        
    }
};

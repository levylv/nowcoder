class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        int i = 0, pos;
        while (!popV.empty())
        {
            pos = find(pushV.begin(), pushV.end(), popV[0]) - pushV.begin();
            i = 0;
            while (i < popV.size())
            {
                if (popV[i] == pushV[pos])
                {
                    popV.erase(popV.begin()+i);
                    pushV.erase(pushV.begin()+pos--);
                }
                else i++;
            }
            if (pos >= 0)
                return false;
        }
        return true;
        
    }
    
};

//其实可以直接按照进出栈的思路写代码，我这样是找出规律按规律写，略复杂

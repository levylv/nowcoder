class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.size() == 0)
            return false;
        return isLegal(sequence, 0, sequence.size()-1);

    }

    bool isLegal(vector<int> array, int l, int r)
    {
        int pos, i=l;
        if (l >= r) return true;
        while (i<r&&array[i++]<array[r]);
        pos = i - 1;
        while (i < r)
        {
            if (array[i++] < array[r])
                return false;
        }
        return isLegal(array, l, pos) && isLegal(array, pos+1, r-1);
    }
};

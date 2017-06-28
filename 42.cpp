class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int len = array.size();
        int left = 0;
        int right = len - 1;
        vector<int> v;
        int min = array[len-1] * array[len-2];
        int small, big;
        bool flag = false;
        while (left < right)
        {
            if (array[left] + array[right] > sum)
                right--;
            if (array[left] + array[right] == sum)
            {
                flag = true;
                if (array[left] * array[right] < min)
                {
                    min = array[left] * array[right];
                    small = array[left];
                    big = array[right];
                }
                left++;
            }
            if (array[left] + array[right] < sum)
                left++;
        }
        if (flag == false)
            return v;
        v.push_back(small);
        v.push_back(big);
        return v;
    }
};

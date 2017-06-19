//冒泡,o((n-k)*k)
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if (input.empty() || k > input.size()) return res;
        int temp;
        for (int i = 0; i < k; i++)
        {
            size_t j = 0;
            for (; j + 1 < (input.size() - i); j++)
            {
                if (input[j] < input[j+1])
                {
                    temp = input[j];
                    input[j] = input[j+1];
                    input[j+1] = temp;
                }
            }
            res.push_back(input[j]);
        }
        return res;
    }
};

//堆排, O(nlogk), 只建k个元素的最大堆。

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if (input.empty() || k > input.size() || k <= 0) return res;
        res.assign(input.begin(), input.begin()+k);
        int i;
        for (i = res.size()/2 - 1;i>=0; i--)
        {
            HeapAdjust(res, i);
        }
        for (i = k; i < input.size(); i++)
        {
            if (input[i] < res[0])
            {
                res[0] = input[i];
                HeapAdjust(res, 0);
            }
        }

        return res;

        
    }
    
    void HeapAdjust(vector<int> &a, int i)
    {
        int j = 2 * i +1;
        int n = a.size(), temp;
        while ( j < n)
        {
            if (j + 1 < n && a[j+1] > a[j])
                j++;
            if (a[j] > a[i])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                i = j;
                j = 2 * i + 1;
            }
            else 
                break;
        }
    }

};

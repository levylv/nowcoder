// 利用递归，O(nlogn)
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        return FindSubArray(array, 0, array.size()-1);
    
    }

    int FindSubArrayCross(vector<int> array, int left, int mid, int right)
    {
        int sum = 0;
        int max = array[mid];
        for (int i=mid; i >= left; i--)
        {
            sum += array[i];
            if (sum > max)
                max = sum;
        }
        sum = max;
        for (int i=mid+1;i <= right;i++)
        {
            sum += array[i];
            if (sum > max)
                max = sum;
        }
        return max;
    }

    int FindSubArray(vector<int> array, int left, int right)
    {
        if (left > right) return 0;
        if (left == right) return array[left];
        int mid  = (left + right) / 2;
        int leftsum, rightsum, crosssum;
        leftsum = FindSubArray(array, left, mid);
        rightsum = FindSubArray(array, mid+1, right);
        crosssum = FindSubArrayCross(array, left, mid, right);
        if (leftsum >= rightsum && leftsum >= crosssum) return leftsum;
        else if (rightsum >= leftsum && rightsum >= crosssum) return rightsum;
        else return crosssum;
    }
};

// 动归思想，O(n)

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int max = array[0];
        int sum = 0;
        for (size_t i=0;i<array.size();i++)
        {
            if (sum <= 0)
                sum = array[i];
            else
                sum += array[i];
            if (sum > max)
                max = sum;
        }
        return max;
    }

};

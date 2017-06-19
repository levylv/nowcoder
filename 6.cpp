class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.size() == 0)
        {
            return 0;
        }
        else 
        {
            int left = 0;
            int right = rotateArray.size() - 1;
            int mid;
            while (rotateArray[left] >=  rotateArray[right])
            {
                mid = (left + right) / 2;
                if (right == left + 1)
                {
                    return rotateArray[right];
                }
                if (rotateArray[mid] >= rotateArray[left])
                {
                    left = mid;
                    continue;
                }
                if (rotateArray[mid] <= rotateArray[right])
                {
                    right = mid;
                    continue;
                }
            }
            return  rotateArray[left];
        }

        
    }

};

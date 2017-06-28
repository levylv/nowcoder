#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int len = data.size();
        if (len > 0)
        {
            int left = GetFirstK(data, k, len,0, len-1);
        	int right = GetLastK(data, k, len,0, len-1);
            if (left > -1 && right > -1)
            	return right - left +1;
        }
         return 0;
       

    } 

    int GetFirstK(vector<int> data,int k, int len, int left, int right)
    {
        if (left <= right)
        {
            int mid = (left + right) / 2;
            if (data[mid] == k)
            {
                if ((mid > 0 &&data[mid-1] != k) || mid == 0)
                    return mid;
                return GetFirstK(data, k, len, left, mid-1);
            }
            else if (data[mid] > k)
                return GetFirstK(data, k, len, left, mid-1);
            else
                return GetFirstK(data, k, len, mid+1, right);
            
        }
        else
            return -1;
    }

    int GetLastK(vector<int> data,int k, int len, int left, int right)
    {
        if (left <= right)
        {
            int mid = (left + right) / 2;
            if (data[mid] == k)
            {
                if ((mid < len-1 && data[mid+1] != k) || mid ==len-1)
                    return mid;
                return GetLastK(data, k, len, mid+1, right);
            }
            else if (data[mid] > k)
                return GetLastK(data, k, len, left, mid-1);
            else
                return GetLastK(data, k, len, mid+1, right);
            
        }
        else
            return -1;
    }
};

int main()
{
    Solution s;
    int a[] = {1,2,3,3,3,3,4,5};
    vector<int> data(a, a+8);
    cout << s.GetNumberOfK(data, 3)<<endl;
}

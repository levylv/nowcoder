#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int InversePairs(vector<int> data) {
        if (data.size() <= 0)
            return 0;
        return MergeSort(data, 0, data.size()-1);
    }

    int Merge(vector<int> &data, int left, int mid, int right)
    {
        vector<int> l(data.begin()+left, data.begin()+mid+1);
        vector<int> r(data.begin()+mid+1, data.begin()+right+1);
        int n1 = mid - left;
        int n2 = right - mid - 1;
        int count = 0;
        while (n1 >= 0 && n2 >= 0)
        {
            if (l[n1] > r[n2])
            {
                data[right--] = l[n1--];
                count += n2+1;
                count %= 1000000007;
            }
            else
                data[right--] = r[n2--];
        }
        for (;n1 >= 0; n1--)
        {
            data[right--] = l[n1];
        }
        for (;n2 >= 0; n2--)
        {
            data[right--] = r[n2];
        }
        return count;

    }

    int MergeSort(vector<int> &data, int left, int right)
    {
        if (left < right)
        {
            int mid = (left + right) / 2;
            int count1 = MergeSort(data, left, mid) % 1000000007;
            int count2 = MergeSort(data, mid+1, right) % 1000000007;
            int count3 = Merge(data, left, mid, right) % 1000000007;
            return (count1+count2+count3) % 1000000007;
        }
        else
            return 0;
    }

};

int main()
{
    Solution s;
    int a[] = {7, 5, 6, 4, 1};
    vector<int> data(a, a+5); 
    cout << s.InversePairs(data) << endl;
}


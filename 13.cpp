//直接用空间换取时间
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> odd;
        vector<int> even;
        for (int i=0;i<array.size();i++)
        {
            if (array[i] % 2 !=0)
            {
                odd.push_back(array[i]);
            }
            else
            {
                even.push_back(array[i]);
            }
        }
        odd.insert(odd.end(),even.begin(),even.end());
        array = odd;
        
    }
};


//类似插入
class Solution
{
public:
    void reOrderArray(vector<int> &array)
    {
        int i, j, temp;
        for (i=0;i<array.size();i++)
        {
            if (array[i]&1)
            {
                j = i-1;
                while(j>=0&&!(array[j]&1))
                {
                    temp = array[j];
                    array[j] = array[j+1];
                    array[j+1] = temp;
                    j--;
                }
            }
        }
    }
}





#include<iostream>
using namespace std;

class Solution {
public:
     int  NumberOf1(int n) {
         int x=1;
         int length = sizeof(int) * 8;
         int i=0;
         int count=0;
         while(i < length)
         {
             if (x<<i&n)
             {
                 count++;
             }
             i++;
         }
         return count;
         
     }
};

int main()
{
    Solution s;
    cout << s.NumberOf1(-1) << endl;

}

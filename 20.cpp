class Solution {
public:
    vector<int> s;
    void push(int value) {
        s.push_back(value);
        
    }
    void pop() {
        s.erase(s.end()-1);
        
    }
    int top() {
        return s.back();
        
    }
    int min() {
        int min = top();
        for (int i=0;i<s.size();i++)
        {
            if (s[i] < min)
            {
                min = s[i];
            }
        }
        return min;
    }
};

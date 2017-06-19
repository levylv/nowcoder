class Solution
{
public:
    void push(int node) {
        stack1.push(node);
        
    }

    int pop() {
        int x;
        if (stack2.empty())
        {
            while (stack1.empty()!=true)
            {
                x = stack1.top();
                stack2.push(x);
                stack1.pop();
            }
        }
        x = stack2.top();
        stack2.pop();
        return x;
        
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

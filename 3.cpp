/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        stack<int> s;
        vector<int> v;
        while(head != NULL)
        {
            s.push(head->val);
            head = head -> next;
        }
        while (s.empty()!=true)
        {
            v.push_back(s.top());
            s.pop();
        }
        return v;
        
    }
};

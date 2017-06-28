#include <iostream>
using namespace std;

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if (pHead == NULL)
            return NULL;
        ListNode* p_first = pHead;
        ListNode* p_last = pHead->next;
        ListNode* p_temp = NULL;
        ListNode* p_head = NULL;
        bool flag = false;
        while (p_last != NULL)
        {
            if (p_last->val == p_first->val)
            {
                p_last = p_last->next;
                flag = true;
            }
            else if (!flag)
            {
                p_head = p_first;
                break;
            }
            else 
            {
                p_first = p_last;
                p_last = p_last->next;
                flag = false;
            }
        }
        if (p_last == NULL && !flag)
            return p_first;
        if (p_last == NULL && flag)
            return NULL;
        p_temp = p_head;
        p_first = p_last;
        p_last = p_last->next;
        flag = false;
        while (p_last != NULL)
        {
            if (p_last->val == p_first->val)
            {
                p_last = p_last->next;
                flag = true;
            }
            else if (!flag)
            {
                p_temp = p_first;
                p_first = p_last;
                p_last = p_last->next;
                flag = false;
            }
            else 
            {
                p_temp->next = p_last;
                p_first = p_last;
                p_last = p_last->next;
                flag = false;
            }
        }
        if (p_last == NULL && flag)
            p_temp->next = NULL;
        return p_head;

    }
};

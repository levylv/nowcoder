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
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if (pHead == NULL)
            return NULL;
        int loop = FindLoop(pHead);
        if (loop == 0)
            return NULL;
        ListNode* p_first = pHead;
        ListNode* p_last = pHead;
        for (int i = 0; i < loop; i++)
        {
            p_first = p_first->next;
        }
        while (p_first != p_last)
        {
            p_first = p_first->next;
            p_last = p_last->next;
        }
        return p_last;


    }

    int FindLoop(ListNode* pHead)
    {
        ListNode* p_quick = pHead->next;
        ListNode* p_slow = pHead;
        int count = 1;
        while (p_quick != NULL && p_quick != p_slow)
        {
            if (p_quick->next == NULL)
                return 0;
            p_quick = p_quick->next->next;
            p_slow = p_slow->next;
            count++;
        }
        if (p_quick == NULL)
            return 0;
        return count;
    }
};

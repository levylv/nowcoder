/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if (pHead1 == NULL)
        {
            return pHead2;
        }
        if (pHead2 == NULL)
        {
            return pHead1;
        }
        ListNode *pre = NULL;
        ListNode *rec = pHead1;
        while (pHead1 != NULL && pHead2 != NULL)
        {
            if (pHead1->val <= pHead2->val)
            {
                pre = pHead1;
                pHead1 = pHead1->next;

            }
            else
            {
                ListNode *newP = new ListNode(pHead2->val);
                pre->next = newP;
                newP->next = pHead1;
                pre = newP;
                pHead2 = pHead2->next;
            }
        }
        if (pHead1 == NULL)
        {
            pre->next = pHead2;
        }
        return rec;
                
    }
};

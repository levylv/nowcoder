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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if (pListHead == NULL || k == 0)
        {
            return NULL;
        }
        int count = 1;
        ListNode* copy = pListHead;
        while (count < k)
        {
            if (pListHead->next != NULL)
            {
                pListHead = pListHead->next;
                count++;
            }
            else
            {
                return NULL;
            }
        }
        while (pListHead->next != NULL)
        {
            copy = copy->next;
            pListHead = pListHead->next;
        }
        return copy;

    
    }
};

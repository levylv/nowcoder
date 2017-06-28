#include <iostream>
using namespace std;

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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if (pHead1 == NULL || pHead2 == NULL)
        {
            return NULL;
        }
        int len1 = 0, len2 = 0;
        ListNode *pHead1_copy = pHead1;
        ListNode *pHead2_copy = pHead2;
        while (pHead1_copy != NULL)
        {
            len1++;
            pHead1_copy = pHead1_copy->next;
        }
        while (pHead2_copy != NULL)
        {
            len2++;
            pHead2_copy = pHead2_copy->next;
        }
        while(len1 > len2)
        {
            pHead1 = pHead1->next;
            len1--;
        }
        while(len2 > len1)
        {
            pHead2 = pHead2->next;
            len2--;
        }
        while (pHead1 != pHead2 && pHead1 != NULL)
        {
            pHead1 = pHead1->next;
            pHead2 = pHead2->next;
        }
        return pHead1;
    }
};

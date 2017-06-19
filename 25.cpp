/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if (!pHead) return NULL;
        RandomListNode *tempHead = pHead;
        RandomListNode *tempCHead;
        while (tempHead)
        {
            RandomListNode *pCHead = new RandomListNode(tempHead->label);
            pCHead->next = tempHead->next;
            tempHead->next = pCHead;
            tempHead = pCHead->next;
        }
        tempHead = pHead;
        while (tempHead)
        {
            if (tempHead->random)
            {
                tempHead->next->random = tempHead->random->next;
            }
            tempHead = tempHead->next->next;
        }
        tempHead = pHead;
        tempCHead = pHead->next;
        RandomListNode *temp;
        while (tempHead->next) //空指针->next是会出错的
        {
            temp = tempHead->next;
            tempHead->next = temp->next;
            tempHead = temp;
        }
        return tempCHead;
    }
};


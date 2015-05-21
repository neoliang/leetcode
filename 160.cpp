/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL)
        {
            return NULL;
        }
        unsigned int lenA = 1;
        unsigned int lenB = 1;
        
        ListNode* tailA = headA;
        while(tailA && tailA->next) 
        {
            ++lenA;
            tailA = tailA->next;
        }
        
        ListNode* tailB = headB;
        while(tailB && tailB->next) 
        {
            ++lenB;
            tailB = tailB->next;
        }
        if (tailB != tailA)
        {
            return NULL;
        }
        ListNode* startLess = headA;
        ListNode* startLarge = headB;
        unsigned int mL = lenB - lenA;
        if(lenA > lenB)
        {
            mL = lenA - lenB;
            startLess = headB;
            startLarge = headA;
        }
        
        while(mL >0)
        {
            startLarge = startLarge->next;
            --mL;
        }
        while(startLarge != startLess)
        {
            startLarge = startLarge->next;
            startLess = startLess->next;
        }
        return startLarge;
        
    }
};
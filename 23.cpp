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
public:
    ListNode* merge(ListNode* preA,ListNode* b)
    {
        ListNode* temp = preA->next;
        preA->next = b;
        ListNode* bNext = b->next;
        b->next = temp;
        return bNext;
    }
    
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1 == NULL)
        {
            return l2;
        }
        if(l2 == NULL)
        {
            return l1;
        }
        
        ListNode *head = l1->val < l2->val ? l1:l2;
        ListNode *a = head->next;
        ListNode *preA = head;
        ListNode *b = head == l1 ? l2:l1;
        while(a && b)
        {
            if(a->val < b->val)
            {
                preA = a;
                a = a->next;
            }
            else
            {
                ListNode* temp = b;
                b = merge(preA,b);
                preA = temp;
            }
        }
        while(b)
        {
            ListNode* temp = b;
            b = merge(preA,b);
            preA = temp;
        }
        
        return head;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists,unsigned int s,unsigned int e) {
        if(s == e)
        {
            return lists[s];
        }
        if(s + 1 == e)
        {
            return mergeTwoLists(lists[s],lists[e]);
        }
        else
        {
            ListNode* left = mergeKLists(lists,s,s + (e - s)/2);
            ListNode* right = mergeKLists(lists,s + (e - s)/2 + 1,e);
            return mergeTwoLists(left,right);
        }
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.empty())
        {
            return NULL;
        }
        return mergeKLists(lists,0,lists.size()-1);
    }
};
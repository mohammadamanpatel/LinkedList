class Solution {
public:
    ListNode* hasCycle(ListNode *head) {
        if(head == NULL)
        {
            return NULL;
        }
        if(head->next == NULL)
        {
            return NULL;
        }
        ListNode*slow = head;
        ListNode*fast = head;
        while(slow!=NULL && fast!=NULL)
        {
            fast = fast->next;
            if(fast!=NULL)
            {
                fast = fast->next;
                slow = slow->next;
            }
            if(slow==fast)
            {
                return slow;
            }
        }
        return NULL;
    }
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL)
        {
            return NULL;
        }
        ListNode*start = hasCycle(head);
        if(start==NULL)
        {
            return NULL;
        }
        ListNode*p = head;
        while(p!=start)
        {
            p = p->next;
            start = start->next;
        }
        return start;
    }
};

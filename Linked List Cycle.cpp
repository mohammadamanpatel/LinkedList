class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL)
        {
            return false;
        }
        if(head->next == NULL)
        {
            return false;
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
                return true;
            }
        }
        return false;
    }
};

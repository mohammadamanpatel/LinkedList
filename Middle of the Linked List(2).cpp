class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head == NULL)
    {
        return NULL;
    }
    ListNode*slow = head;
    ListNode*fast = head;
    while(fast!=NULL and slow!=NULL)
    {
        fast = fast->next;
        if(fast!=NULL)
        {
            fast = fast->next; 
            slow = slow->next;
        }
    }
    return slow;
    }
};

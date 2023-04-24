class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode*curr = head;
        while(curr!=NULL)
        {
           if((curr->next!=NULL) and (curr->val == curr->next->val))
           {
             ListNode*temp = curr->next;
             curr->next = curr->next->next;
             temp->next = NULL; 
             delete temp;
           }
           else{
             curr = curr->next;
           }
        }
        return head;
    }
};

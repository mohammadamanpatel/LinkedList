class Solution {
public:
    int lengthFn(ListNode*head)
  {
   ListNode*temp = head;
   int length = 0;
   while(temp!=NULL)
   {
      temp = temp->next; 
      length++;
   }
 return length;
}
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL)
        {
            return NULL;
        }
        if(k>lengthFn(head))
        {
            return head;
        }
        ListNode*prev = NULL;
        ListNode*curr = head;
        ListNode*forward = curr->next;
        int count = 0;
        while(count<k)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            count++; 
        }
        if(forward!=NULL)
        {
            head->next = reverseKGroup(forward,k);
        }
        return prev;
    }
};

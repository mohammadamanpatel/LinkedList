// O(1) Space snd O(n) Time
class Solution {
public:
    ListNode* reverse(ListNode*&head)
{
    //by using recursion
    
    // if(q==NULL)
    // {
    //   return p;
    // }
    // Node*forward = q->next;
    // q->next = p;
    // reverse(q,forward);
    
    //by using loop
    ListNode*p = NULL;
    ListNode*q = head;
    while(q!=NULL)
    {
        ListNode*forward = q->next;
        q->next = p;
        p = q;
        q = forward;
    }
  return p;
}
ListNode*midNode(ListNode*&head)
{
    if(head == NULL)
    {
        return NULL;
    }
    ListNode*slow = head;
    ListNode*fast = head->next;
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
    bool isPalindrome(ListNode* head) {
        ListNode*slow = midNode(head);
        ListNode*reverseLLkahead = reverse(slow->next);
        slow->next = reverseLLkahead;
        ListNode*temp1 = head;
        ListNode*temp2 = reverseLLkahead;
        while(temp2!=NULL)
        { 
            if(temp1->val!=temp2->val)
            {
                return false;
            }
            else{
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
        return true;
    }
};

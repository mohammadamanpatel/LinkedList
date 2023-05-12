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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
        {
            return 0;
        }
        ListNode*oldHead = head;
        int len = lengthFn(head);
        int actualK = (k%len);
        if(actualK == 0)
        {
            return head;
        }
        int newK = len - actualK - 1;
        ListNode*kposition = head;
        for(int i=0;i<newK;i++)
        {
            kposition = kposition->next;
        }
        ListNode*newhead = kposition->next;
        kposition->next = 0;
        ListNode*p = newhead;
        while(p->next)
        {
            p = p->next;
        }
        p->next = head;
        return newhead;
    }
};

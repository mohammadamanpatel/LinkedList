class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       if(list1==NULL)
       {
           return list2;
       }   
       if(list2==NULL)
       {
           return list1;
       }
       ListNode*dummy = new ListNode(-1);
       ListNode*tail = dummy;
       ListNode*a = list1;
       ListNode*b = list2;
       while(a!=NULL and b!=NULL)
       {
           if(a->val<b->val)
           {
               tail->next = a;
               tail=a;
               a = a->next;
           }
           else{
               tail->next = b;
               tail = b;
               b = b->next;
           }
       }
       while(a!=NULL)
       {
           tail->next = a;
           tail = a;
           a=a->next;
       }
       while(b!=NULL)
       {
           tail->next = b;
           tail = b;
           b=b->next;
       }
       return dummy->next;
    }
};

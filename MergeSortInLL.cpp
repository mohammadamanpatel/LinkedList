class Solution {
public:
     ListNode*midNode(ListNode*head)
     {
        ListNode*slow = head;
        ListNode*fast = head->next;
        while(slow!=NULL and fast!=NULL)
        {
            fast = fast->next;
            if(fast!=NULL)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }
        return slow;
     }
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
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode*mid = midNode(head);
        ListNode*leftListhead = head;
        ListNode*rightListhead = mid->next;
        mid->next = NULL; //agar slow->next NULL nhi kiya to link break nhi hoga aur do lists
        
         // galti se pehle call mat kardena pehle mid ke next se link todna
         
        ListNode*leftList = sortList(leftListhead);
        ListNode*rightList = sortList(rightListhead);
                           //nhi ban payegi
        ListNode*sortedList = mergeTwoLists(leftList,rightList);
        return sortedList;
    }
};

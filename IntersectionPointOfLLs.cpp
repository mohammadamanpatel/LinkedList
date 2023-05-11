class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL)
        {
            return headB;
        }
        if(headB==NULL)
        {
            return headA;
        }
        ListNode*t1 = headA;
        ListNode*t2 = headB;
        while(t1->next and t2->next)
        {
            t1=t1->next;
            t2=t2->next;
        }
        if(t1->next == NULL)
        {
            int Blen = 0;
            //agar t1->next nuul hai means t2 list badi hai
            while(t2->next!=NULL)
            {
                t2 = t2->next;
                Blen++;
            }
            while(Blen--)
            {
                headB = headB->next;
            }
        }
        else{
            int Alen = 0;
            while(t1->next!=NULL)
            {
                t1 = t1->next;
                Alen++;
            }
            while(Alen--)
            {
                headA = headA->next;
            }
        }
        while(headA!=headB)
        {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};

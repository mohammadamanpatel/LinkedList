class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        if(!head) return NULL;
        ListNode*slow = head,*fast = head->next,*lastNode = 0;
        int sum = 0;
        while(fast!=NULL)
        {
            if(fast->val != 0)
            {
              sum+=fast->val;
            }
            else
            {
              slow->val = sum;
              sum = 0;
              lastNode = slow; 
              slow = slow->next;
            }
            fast = fast->next;
        }
        ListNode*temp = lastNode->next;
        lastNode->next = NULL;
        while(temp)
        {
            ListNode*next = temp->next;
            delete temp;
            temp = next;
        }
        return head;
    }
};

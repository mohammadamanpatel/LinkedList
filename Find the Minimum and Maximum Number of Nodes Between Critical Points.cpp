class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>ans = {-1,-1};
        ListNode*prev = head;
        ListNode*curr = head->next;
        ListNode*nxt = head->next->next;
        if(!prev) return ans;
        if(!curr) return ans;
        if(!nxt) return ans;
        int FirstCP = -1;
        int LastCP = -1;
        int minDist = INT_MAX;
        int i = 1;
        while(nxt!=nullptr)
        {
           bool CP = ((curr->val > prev->val && curr->val > nxt->val) 
                       || (curr->val < prev->val && curr->val < nxt->val)) ? true : false;
           if(CP and FirstCP == -1)
           {
               FirstCP = i;
               LastCP = i;
           }            
           else if(CP)
           {
               minDist = min(minDist,i-LastCP);
               LastCP = i;
           }
           prev = prev->next;
           curr = curr->next;
           nxt = nxt->next;
           ++i;
        }
        if(FirstCP == LastCP)
        {
            return ans;
        }
        else{
            ans[0] = minDist;
            ans[1] = LastCP - FirstCP;
        }
        return ans;
    }
};

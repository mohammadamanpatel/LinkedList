class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode*temp = head;
        vector<int>arr;
        while(temp!=NULL)
        {
            arr.push_back(temp->val);
            temp = temp->next;
        }
       int s = 0;
       int e = arr.size()-1;
       while(s<=e)
       {
          if(arr[s]==arr[e])
          {
              s++;
              e--;
          }
          else{
              return false;
          }
       }
        return true;
    }
};

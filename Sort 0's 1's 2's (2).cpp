class Solution
{
    public:
    Node*Sort(Node*&head)
    {
          if(head==NULL)
      {
          return NULL;
      }
      if(head->next==NULL)
      {
          return head;
      }
        Node*zero = new Node(-1);
        Node*zeroTail = zero;
        Node*one = new Node(-1);
        Node*oneTail = one;
        Node*two = new Node(-1);
        Node*twoTail = two;
        
        Node*curr = head;
        while(curr!=NULL)
        {
            if(curr->data == 0)
            {
                Node*temp = curr; //curr disappear na ho isliye temp = curr kiya
                curr = curr->next;
                temp->next = NULL;
                zeroTail->next = temp;
                zeroTail = temp;  //tail ko update kiya
            }
            else if(curr->data == 1)
            {
                Node*temp = curr;
                curr = curr->next;
                temp->next = NULL;
                oneTail->next = temp;
                oneTail = temp;
            }
            else if(curr->data == 2){
                Node*temp = curr;
                curr = curr->next;
                temp->next = NULL;
                twoTail->next = temp;
                twoTail = temp;
            }
        }
        // abhi ham one aur two waali dummy node delete kar denge
        Node*temp = one;
        one = one->next;
        temp->next = NULL;
        delete temp;
        
        temp = two;
        two = two->next;
        temp->next = NULL;
        delete temp;
        
        // ab merging
        if(one!=NULL)
        {
            zeroTail->next = one;
            if(two!=NULL)
            {
                oneTail->next = two;
            }
        }
        else{
            if(two!=NULL)
                zeroTail->next = two;
        }
        temp = zero;
        zero = zero->next;
        temp->next = NULL;
        delete temp;
        
        return zero;
    }
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
      if(head==NULL)
      {
          return NULL;
      }
      if(head->next==NULL)
      {
          return NULL;
      }
      head = Sort(head);
      return head;
    }
};

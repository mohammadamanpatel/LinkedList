class Solution
{
    public:
    //Function to remove a loop in the linked list.
     Node* hasCycle(Node *head) {
        if(head == NULL)
        {
            return NULL;
        }
        if(head->next == NULL)
        {
            return NULL;
        }
        Node*slow = head;
        Node*fast = head;
        while(slow!=NULL && fast!=NULL)
        {
            fast = fast->next;
            if(fast!=NULL)
            {
                fast = fast->next;
                slow = slow->next;
            }
            if(slow==fast)
            {
                return slow;
            }
        }
        return NULL;
    }
    Node *detectCycle(Node *head) {
        if(head == NULL)
        {
            return NULL;
        }
        Node*start = hasCycle(head);
        if(start==NULL)
        {
            return NULL;
        }
        Node*p = head;
        while(p!=start)
        {
            p = p->next;
            start = start->next;
        }
        return start;
    }
    void removeLoop(Node* head)
    {
        Node*start = detectCycle(head);
        if(start == NULL)
        {
            return;
        }
        Node*temp = start;
        while(temp->next!=start)
        {
            temp = temp->next;
        }
        temp->next = NULL;
    }
};

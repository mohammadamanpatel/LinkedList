class Solution {
public:
    Node*ClonedList(Node*head)
    {
        if(!head) return nullptr;
        Node*oldList = head;
        while(oldList)
        {
            Node*clonedList = new Node(oldList->val);
            clonedList->next = oldList->next;
            oldList->next = clonedList;
            oldList = oldList->next->next;
        }
        oldList = head;
        while(oldList)
        {
            Node*clonedList = oldList->next; //ye ham isliye kar rhe ham bata rhe hai ki clonedList 
                                             //oldList->next hai
            clonedList->random = oldList->random ? oldList->random->next : nullptr;
            oldList = oldList->next->next;
        }
        oldList = head;
        Node*ClonedHead = oldList->next;
        while(oldList)
        {
            Node*ClonedNode = oldList->next; 
            oldList->next = oldList->next->next;
            if(ClonedNode->next){
              ClonedNode->next = ClonedNode->next->next;
            }
            oldList = oldList->next; 
        }
        return ClonedHead;
    }
    Node* copyRandomList(Node* head) {
        return ClonedList(head);
    }
};

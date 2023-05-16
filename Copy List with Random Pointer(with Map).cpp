class Solution {
public:
    Node*copiedList(Node*head,unordered_map<Node*,Node*>&mp)
    {
        if(!head) return 0;
        Node*newNode = new Node(head->val);
        //agar me old node ke map se newNode ko joint karu to ek connection
        // jisse newnode bhi usi direction me                        
        //point karega jese old node karta tha ye ham random ptrs ko point karaane ke liye kar rhe hai
        //basically puraani node se nayi node ki mapping hai
        mp[head] = newNode; 
        newNode->next = copiedList(head->next,mp);
        if(head->random)
        {
           newNode->random = mp[head->random];    
        }     
        return newNode;               
    }
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>mp;
        return copiedList(head,mp);
    }
};

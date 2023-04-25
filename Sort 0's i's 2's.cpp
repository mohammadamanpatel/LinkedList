
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        int zero = 0;
        int one = 0;
        int two = 0;
        Node*temp = head;
        while(temp)
        {
            if(temp->data==0)
            {
                zero++;
            }
            if(temp->data==1)
            {
                one++;
            }
            if(temp->data==2)
            {
                two++;
            }
            temp = temp->next;
        }
        temp = head;
        while(temp)
        {
            if(zero!=0)
            {
                temp->data = 0;
                zero--;
            }
            else if(one!=0)
            {
                temp->data = 1;
                one--;
            }
            else{
                temp->data = 2;
                two--;
            }
            temp = temp->next;
        }
        return head;
    }

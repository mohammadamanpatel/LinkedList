class Solution
{
public:
    int lengthFn(ListNode *head)
    {
        ListNode *temp = head;
        int length = 0;
        while (temp != NULL)
        {
            temp = temp->next;
            length++;
        }
        return length;
    }
    ListNode *middleNode(ListNode *head)
    {
        ListNode *temp = head;
        if (head == NULL)
        {
            return NULL;
        }
        int length = lengthFn(head);
        if (length % 2 == 0)
        {
            int i = 1;
            while (i <= length / 2)
            {
                temp = temp->next;
                i++;
            }
        }
        else
        {
            int i = 1;
            while (i < (length / 2) + 1)
            {
                temp = temp->next;
                i++;
            }
        }
        return temp;
    }
};

void getValueFromLast(SinglyLinkedListNode*head,int &positionFromTail,int&ans)
{
  if(head == NULL)
  {
     return;  
  }
  getValueFromLast(head->next,positionFromTail,ans);
  if(positionFromTail == 0)
  {
    ans = head->data;
  }
  positionFromTail--;
}
int getNode(SinglyLinkedListNode* llist, int positionFromTail) {
   int ans = -1;
   getValueFromLast(llist,positionFromTail,ans);
   return ans;
}

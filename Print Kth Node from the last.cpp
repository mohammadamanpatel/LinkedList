SinglyLinkedListNode*reverse(SinglyLinkedListNode*head)
{
   SinglyLinkedListNode*p = NULL;
   SinglyLinkedListNode*q = head;
   SinglyLinkedListNode*forward = q->next;
   while(q!=NULL)
   {
     forward = q->next;
     q->next = p;
     p = q;
     q = forward;
   } 
   return p;
}
int getNode(SinglyLinkedListNode* llist, int positionFromTail) {
  llist = reverse(llist);
  SinglyLinkedListNode*p = llist;
  int i = 0;
  while(i<positionFromTail)
  {
    p = p->next;
    i++;
  }
  return p->data;
}

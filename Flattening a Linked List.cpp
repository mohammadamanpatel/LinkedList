Node*mergeLists(Node*a,Node*b)
{
    if(!a)return b;
    if(!b)return a;
    Node*ans = 0;
    if(a->data < b->data)
    {
        ans = a;
        a->bottom = mergeLists(a->bottom,b);
    }
    else{
        ans = b;
        b->bottom = mergeLists(a,b->bottom);
    }
    return ans;
}
Node *flatten(Node *root)
{
   if(!root)
   {
       return 0;
   }
   Node*mergell = mergeLists(root,flatten(root->next));
   return mergell;
}

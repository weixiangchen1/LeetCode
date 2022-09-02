void LListRemoveOdd(LIST *list)
{
    int count=0;
    NODE* prev=list->head;
    NODE* cur=prev->next;
    while(cur){
        if(cur->data%2!=0){
            prev->next=prev->next->next;
            count++;
            cur=prev->next;
        }
        else{
            prev=cur;
            cur=cur->next;
        }
    }
    list->length=list->length-count;
}

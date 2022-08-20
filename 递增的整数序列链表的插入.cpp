List Insert( List L, ElementType X )
{
    struct Node* newnode = (List)malloc(sizeof(struct Node));
    newnode->Data = X;
    newnode->Next = NULL;
    List head = L;
    while(L->Next&&L->Next->Data<X)
    {
        L = L-> Next;
    }
    newnode->Next = L->Next;
    L->Next = newnode;
    return head;
}

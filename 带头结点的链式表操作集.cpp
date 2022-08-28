typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

List MakeEmpty(); 
Position Find( List L, ElementType X );
bool Insert( List L, ElementType X, Position P );
bool Delete( List L, Position P );



List MakeEmpty()
{
    struct LNode* L = (struct LNode*)malloc(sizeof(struct LNode));
    L->Next = NULL;
    return L;
}
Position Find( List L, ElementType X )
{
    L = L->Next;
    while(L!= NULL)
    {
        if(L->Data==X)
            return L;
        L = L->Next;
    }
    return ERROR;
}
bool Insert( List L, ElementType X, Position P )
{
    List insert = (List)malloc(sizeof(List));
    insert->Data = X;
    insert->Next = NULL;
    List k= L;
    while(k){
        if(k->Next==P)
        {
            insert->Next = P;
            k->Next = insert;
            return true;
        }
        k = k->Next;
    }
    printf("Wrong Position for Insertion\n");
	return false;
}
bool Delete( List L, Position P ){
	if(L==P){
		L=L->Next;
		return true;
	}
	while(L){
		if(L->Next==P){
			L->Next=P->Next;
			return true;	
		}
		L=L->Next;
	}
	printf("Wrong Position for Deletion\n");
	return false;
}


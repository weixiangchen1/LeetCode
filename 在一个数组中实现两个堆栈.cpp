Stack CreateStack( int MaxSize )
{
    struct SNode *S=NULL;
    S=(struct SNode *)malloc(sizeof(struct SNode));
    S->Data=(int *)malloc(MaxSize*sizeof(int));
    S->Top1=-1;
    S->Top2=MaxSize;
    S->MaxSize=MaxSize;
    return S;
}
bool Push( Stack S, ElementType X, int Tag )
{
    if(S->Top2-S->Top1==1)
    {
        printf("Stack Full\n");
        return false;
    }
    else
    {
        if(Tag==1) S->Data[++(S->Top1)]=X;
        else if(Tag==2) S->Data[--(S->Top2)]=X;
        return true;
    }
}
ElementType Pop( Stack S, int Tag )
{
    if(Tag==1)
    {
        if(S->Top1==-1)
        {
            printf("Stack %d Empty\n",Tag);
            return ERROR;
        }
        else return S->Data[(S->Top1)--];
    }
    else if(Tag==2)
    {
        if(S->Top2==S->MaxSize)
        {
            printf("Stack %d Empty\n",Tag);
            return ERROR;
        }
        else 
        {
            return S->Data[(S->Top2)++];
        }
    }
}


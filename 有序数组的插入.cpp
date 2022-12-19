bool Insert( List L, ElementType X )
{
	int i, j;
	for(i=0;i<=L->Last;i++)
	{
	    if(L->Data[i]==X) 
               return false;
	    else if(L->Data[i]<X)
	       break;
	}
	for(j=L->Last;j>=i;j--)
        {
           L->Data[j+1]=L->Data[j];
        }
	   
	L->Data[i]=X;
        L->Last++;
	return true;
}

bool Push( Stack S, ElementType X ){
	if(S->Top==S->MaxSize){
		printf("Stack Full\n");
		return ERROR;
	}
	else{
		S->Data[S->Top]=X;
		S->Top++;
        return true;
	}
}
ElementType Pop( Stack S ){
	if(S->Top==0){
		printf("Stack Empty\n");
		return ERROR;
	}
	else{
		S->Top--;
		return S->Data[S->Top];
	}
}

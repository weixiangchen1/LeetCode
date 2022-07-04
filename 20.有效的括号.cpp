/*
 * @lc app=leetcode.cn id=20 lang=c
 *
 * [20] 有效的括号
 */

// @lc code=start
typedef char STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}Stack;

// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
bool StackEmpty(Stack* ps)
{
	assert(ps);

	return ps->top == 0;
}
// 初始化栈 
void StackInit(Stack* ps)
{
	assert(ps);

	ps->a = NULL;
	ps->capacity = ps->top = 0;
}
// 入栈 
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);
	
	if (ps->capacity == ps->top)
	{
		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* tmp = realloc(ps->a, sizeof(STDataType) * newCapacity);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}

		ps->a = tmp;
		ps->capacity = newCapacity;
	}

	ps->a[ps->top] = data;
	ps->top++;
}
// 出栈 
void StackPop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));

	ps->top--;
}
// 获取栈顶元素 
STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));

	return ps->a[ps->top - 1];
} 
// 获取栈中有效元素个数 
int StackSize(Stack* ps)
{
	assert(ps);

	return ps->top;
}

// 销毁栈 
void StackDestroy(Stack* ps)
{
	assert(ps);

	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}
bool isValid(char * s){
    Stack st;
    StackInit(&st);
    while(*s)
    {
        if(*s == '(' || *s == '{' || *s == '[')
        {
            StackPush(&st, *s);
            s++;
        }
        else
        {
            //遇到右括号，但是栈里面没有左括号
            if(StackEmpty(&st))
            {
                StackDestroy(&st);
                return false;
            }
            STDataType tmp = StackTop(&st);
            StackPop(&st);
            if((*s == ')' && tmp != '(')
            || (*s == '}' && tmp != '{')
            || (*s == ']' && tmp != '['))
            {
                StackDestroy(&st);
                return false;
            }
            else
            {
                s++;
            }
        }
    }
    bool ret = StackEmpty(&st);
    StackDestroy(&st);

    return ret;
}

// @lc code=end


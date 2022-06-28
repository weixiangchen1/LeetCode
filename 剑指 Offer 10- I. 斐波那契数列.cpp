int fib(int n){
    if(n == 0)
        return 0;
    if(n == 1|| n == 2)
        return 1;
    int a = 1;
    int b = 1;
    int c = 1;
    while(n > 2)
    {
        a = b;
        b = c;
        c = (a + b)%1000000007;
        n--;
    }
    return c%1000000007;
}

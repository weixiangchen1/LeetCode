bool isPalindrome(int x){
    int ret = x;
    long int sum = 0;
    if(x<0)
    {
        return false;
    }
    else
    {
        while(ret)
        {
        sum = sum*10 + ret%10;
        ret = ret/10;
        }
    }
    return sum == x;

}

int hammingWeight(uint32_t n) {
    int i = 0;
    int count = 0;
    for(i = 0; i < 32; i++)
    {
        if(n & 1 == 1)
            count++;
        n >>= 1;
    } 
    return count;
}

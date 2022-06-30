int missingNumber(int* nums, int numsSize){
    int x = 0;
    for(int i = 0; i <= numsSize; i++)
    {
        x ^= i;
    }
    for(int i = 0; i < numsSize; i++)
    {
        x ^= nums[i];
    }

    return x;
}

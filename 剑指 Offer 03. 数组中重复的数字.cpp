int findRepeatNumber(int* nums, int numsSize){
    int i = 0;
    int flag[100007] = {0};
    for(i=0; i<numsSize; i++)
    {
        flag[nums[i]]++;
        if(flag[nums[i]] > 1)
            break;
    }
            return nums[i];
    
}

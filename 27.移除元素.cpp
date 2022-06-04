int removeElement(int* nums, int numsSize, int val){
    int dst = 0;
    int src = 0;
    while(dst < numsSize)
    {
        if(nums[dst] != val)
        {
            nums[src] = nums[dst];
            src++;
            dst++;
        }
        else
        {
            dst++;
        }
    }

    return src;
}

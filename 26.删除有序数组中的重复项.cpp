int removeDuplicates(int* nums, int numsSize){
    if(numsSize == 0)
        return 0;
    int i = 0;
    int j = 0;
    int tmp = 0;
    while(++j < numsSize)
    {
        if(nums[i] != nums[j])
        {
            nums[tmp] = nums[i];
            tmp++;
            i = j; 
        }
    }
    nums[tmp] = nums[i];
    tmp++;
    return tmp;
}

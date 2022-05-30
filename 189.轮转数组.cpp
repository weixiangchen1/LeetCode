void reverse(int left, int right, int* nums)
{
    while(left < right)
    {
        int tmp = nums[left];
        nums[left] = nums[right];
        nums[right] = tmp;
        left++;
        right--;
    }
}

void rotate(int* nums, int numsSize, int k){
    if(k > numsSize)
    {
        k %= numsSize;
    }
    
    reverse(0, numsSize-1, nums);
    reverse(0, k-1, nums);
    reverse(k, numsSize-1, nums);

}

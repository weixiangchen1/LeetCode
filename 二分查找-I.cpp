class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums int整型vector 
     * @param target int整型 
     * @return int整型
     */
    int search(vector<int>& nums, int target) {
        // write code here
        int left = 0;
        int right = nums.size()-1;
        
        if(nums.size() == 0)
        {
            return -1;
        }
        
        while(left <= right)
        {
            int mid = (left + right) / 2;
            
            if(nums[mid] > target)
            {
                right = mid - 1;
            }
            else if(nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                return mid;
            }
            
        }
        
        return -1;
        
    }
};

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int index = nums.size() - 1;
        vector<int> ans(nums.size(), 0);
        while (left <= right) {
            if (nums[left]*nums[left] > nums[right]*nums[right]) {
                ans[index--] = nums[left]*nums[left];
                left++;
            }
            else {
                ans[index--] = nums[right]*nums[right];
                right--;
            }
        }

        return ans;
    }
};

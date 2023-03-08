class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums[nums.size() - 1] < target) return nums.size();
        
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }

        return l;
    }
};

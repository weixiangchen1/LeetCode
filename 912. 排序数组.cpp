class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        int gap = n;
        while (gap > 1) {
            gap = gap / 2;
            for (int i = 0; i < n - gap; ++i) {
                int end = i;
                int x = nums[end + gap];
                while (end >= 0) {
                    if (nums[end] > x) {
                        nums[end + gap] = nums[end];
                        end -= gap;
                    }
                    else {
                        break;
                    }
                }
                nums[end + gap] = x;
            }
        }
        return nums;
    }
};

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int res = 1;
        for (int i = 1, j = 0; i < nums.size(); ++i) {
            if (nums[i - 1] >= nums[i]) {
                j = i;
            }
            else {
                res = max(res, i - j + 1);
            }
        }

        return res;
    }
};

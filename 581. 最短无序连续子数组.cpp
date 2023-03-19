class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> copy(nums);
        sort(copy.begin(), copy.end());
        int start = 0, end = -1;
        for (int k = 0; k < nums.size(); ++k)
        {
            if (nums[k] != copy[k]) 
            {
                start = k;
                break;
            }
        }
        for (int k = nums.size() - 1; k >= 0; --k)
        {
            if (nums[k] != copy[k])
            {
                end = k;
                break;
            }
        }

        return end - start + 1;
    }
};
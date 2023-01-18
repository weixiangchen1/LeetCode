class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        long long ans = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
            if (i && nums[i] == nums[i-1]) continue;

            int l = i + 1, r = n - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (abs(sum - target) < abs(ans - target)) 
                    ans = sum;

                if (sum > target) {
                    r--;
                    continue;
                }
                if (sum < target) {
                    l++;
                    continue;
                }

                return target;
            }
        }

        return ans;
    }
};

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return vector<int>{-1, -1};
        vector<int> ans;
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        if (nums[l] != target){
            return vector<int>{-1, -1};
        }  
        else {
            ans.push_back(l);

            int left = 0, right = nums.size() - 1;
            while (left < right) {
                int mid = (left + right + 1) >> 1;
                if (nums[mid] <= target) left = mid;
                else right = mid - 1; 
            }

            ans.push_back(left);
        }

        return ans;
    }
};

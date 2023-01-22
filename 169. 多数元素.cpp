class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size = nums.size();
        unordered_map<int, int> nums_count;
        for (auto& x : nums) {
            nums_count[x]++;
        }
        for (auto& it : nums_count) {
            if (it.second > size / 2)
                return it.first;
        }
        return -1;
    }
};

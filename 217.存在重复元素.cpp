class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> hash;
        for (auto& x : nums) {
            hash[x]++;
        }
        for (auto& it : hash) {
            if (it.second >= 2) {
                return true;
            }
        }
        return false;
    }
};

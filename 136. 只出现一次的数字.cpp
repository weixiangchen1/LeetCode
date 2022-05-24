class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int value = 0;
        for(auto e : nums)
        {
            value ^= e;
        }

        return value;
    }
};

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> answer(nums.size(), 1);

		int left = 1;
		for (int i = 1; i < nums.size(); ++i) {
			left = left * nums[i - 1];
			answer[i] = answer[i] * left;
		}
		int right = 1;
		for (int i = nums.size() - 1; i > 0; --i) {
			right = right * nums[i];
			answer[i - 1] = answer[i - 1] * right;
		}

		return answer;
	}
};
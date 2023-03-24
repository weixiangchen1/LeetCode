class NumArray {
public:
	NumArray(vector<int>& nums) {
		sum.resize(nums.size() + 1);
		for (int i = 0; i < nums.size(); ++i)
		{
			sum[i + 1] = sum[i] + nums[i];
		}
	}

	int sumRange(int left, int right) {
		left += 1, right += 1;
		return sum[right] - sum[left - 1];
	}

private:
	vector<int> sum;
};

/**
* Your NumArray object will be instantiated and called as such:
* NumArray* obj = new NumArray(nums);
* int param_1 = obj->sumRange(left,right);
*/
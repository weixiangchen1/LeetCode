class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.empty()) return -1;

		// ���ֳ���ת�ķֽ��
		int l = 0, r = nums.size() - 1;
		while (l < r) {
			int mid = l + r + 1 >> 1;
			if (nums[mid] >= nums[0]) l = mid;
			else r = mid - 1;
		}

		// ȷ��target�ڵ����䣬���ֲ���
		if (target >= nums[0]) l = 0;
		else l = r + 1, r = nums.size() - 1;
		while (l < r) {
			int mid = l + r >> 1;
			if (nums[mid] >= target) r = mid;
			else l = mid + 1;
		}
		if (target == nums[r]) return r;
		else return -1;
	}
};
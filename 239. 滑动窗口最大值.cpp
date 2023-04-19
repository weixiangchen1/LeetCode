class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> ans;
		deque<int> dq;   // 存储值下标
		for (int i = 0; i < nums.size(); ++i) {
			// 判断队头是否已经滑出了窗口
			if (!dq.empty() && dq.front() < i - k + 1)
				dq.pop_front();
			// 如果队尾的值小于等于当前值，删除
			while (!dq.empty() && nums[dq.back()] <= nums[i])
				dq.pop_back();
			dq.push_back(i);
			if (i >= k - 1) ans.push_back(nums[dq.front()]);
		}

		return ans;
	}
};
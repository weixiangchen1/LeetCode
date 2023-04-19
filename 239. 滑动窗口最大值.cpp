class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> ans;
		deque<int> dq;   // �洢ֵ�±�
		for (int i = 0; i < nums.size(); ++i) {
			// �ж϶�ͷ�Ƿ��Ѿ������˴���
			if (!dq.empty() && dq.front() < i - k + 1)
				dq.pop_front();
			// �����β��ֵС�ڵ��ڵ�ǰֵ��ɾ��
			while (!dq.empty() && nums[dq.back()] <= nums[i])
				dq.pop_back();
			dq.push_back(i);
			if (i >= k - 1) ans.push_back(nums[dq.front()]);
		}

		return ans;
	}
};
class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		priority_queue<pair<int, int>> pq;
		unordered_map<int, int> hash;
		vector<int> ans;
		for (auto x : nums) hash[x]++;
		for (auto x : hash) pq.push(make_pair(x.second, x.first));

		while (k-- && !pq.empty())
		{
			ans.push_back(pq.top().second);
			pq.pop();
		}

		return ans;
	}
};
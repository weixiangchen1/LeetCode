class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> ans;
		if (intervals.size() == 0) return ans;

		sort(intervals.begin(), intervals.end());
		int start = -1, end = -1;
		for (auto interval : intervals)
		{
			if (end < interval[0])
			{
				if (end != -1) ans.push_back({ start, end });
				start = interval[0];
				end = interval[1];
			}
			else
			{
				end = max(end, interval[1]);
			}
		}
		if (end != -1) ans.push_back({ start, end });

		return ans;
	}
};
class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		vector<vector<int>> ans;
		if (intervals.size() == 0)
		{
			ans.push_back(newInterval);
			return ans;
		}

		intervals.push_back(newInterval);
		sort(intervals.begin(), intervals.end());

		int start = 0, end = -1;
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
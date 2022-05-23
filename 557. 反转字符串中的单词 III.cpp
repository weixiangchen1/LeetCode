class Solution {
public:
	string reverseWords(string s) {
		string cur, ret;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] != ' ')
			{
				cur += s[i];
			}
			else
			{
				reverse(cur.begin(), cur.end());
				ret += cur;
				ret += s[i];
				cur.clear();
			}
		}
		if (!cur.empty())
		{
			reverse(cur.begin(), cur.end());
			ret += cur;
		}

		// for (int i = s.size() - 1; s[i] != ' '; --i)
		// {
		// 	ret += s[i];
		// }

		return ret;
	}
};

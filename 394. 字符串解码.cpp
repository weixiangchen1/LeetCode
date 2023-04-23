class Solution {
public:
	string decodeString(string s) {
		stack<int> cnt;
		stack<string> strs;
		int num = 0;
		string cur;
		for (int i = 0; i < s.size(); ++i)
		{
			if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
			{
				cur += s[i];
			}
			else if (s[i] >= '0' && s[i] <= '9')
			{
				num = num * 10 + s[i] - '0';
			}
			else if (s[i] == '[')
			{
				cnt.push(num);
				strs.push(cur);
				num = 0;
				cur.clear();
			}
			else if (s[i] == ']')
			{
				int t = cnt.top();
				cnt.pop();
				string tmp = cur;
				cur = strs.top();
				strs.pop();
				while (t--) cur += tmp;
			}
		}

		return cur;
	}
};
class Solution {
public:
	bool isIsomorphic(string s, string t) {
		return _isIsomorphic(s, t) && _isIsomorphic(t, s);
	}

	bool _isIsomorphic(string s, string t) {
		unordered_map<char, char> hash;
		for (int i = 0; i < s.size(); ++i) {
			char c1 = s[i], c2 = t[i];
			if (hash.count(c1)) {
				if (hash[c1] == c2) continue;
				else return false;
			}
			else {
				hash[c1] = c2;
			}
		}
		return true;
	}
};
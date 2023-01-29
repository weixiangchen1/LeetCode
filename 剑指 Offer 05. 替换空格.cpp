class Solution {
public:
    string replaceSpace(string s) {
        string ans;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ') {
                ans += s[i];
            }
            else {
                ans += "%20";
            }
        }

        return ans;
    }
};

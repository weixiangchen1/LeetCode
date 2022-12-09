class Solution {
public:
    int romanToInt(string s) {
        unordered_map<int, int> num_map;
        num_map['I'] = 1, num_map['V'] = 5, num_map['X'] = 10, num_map['L'] = 50,
        num_map['C'] = 100, num_map['D'] = 500, num_map['M'] = 1000;
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (num_map[s[i]] < num_map[s[i+1]] && i+1 < s.size()) {
                ans -= num_map[s[i]];
            }
            else {
                ans += num_map[s[i]];
            }
        }

        return ans;
    }
};

string str[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

class Solution {
public:
    void _letterCombinations(const string& digits, size_t i, string combinStr, vector<string>& ans)
    {
        if(i >= digits.size())
        {
            ans.push_back(combinStr);
            return;
        }

        string s = str[digits[i]-'0'];
        for(size_t j=0; j<s.size(); ++j)
        {
            _letterCombinations(digits, i+1, combinStr+s[j], ans);
        }
    }

    vector<string> letterCombinations(string digits) {
        string combinStr;
        vector<string> ans;
        if(digits.empty())
        {
            return ans;
        }

        _letterCombinations(digits, 0, combinStr, ans);

        return ans;
    }
};

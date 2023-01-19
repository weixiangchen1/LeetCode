class Solution {
public:
    vector<string> ans;

    vector<string> generateParenthesis(int n) {
        dfs(n, 0, 0, "");
        return ans;
    }

    void dfs(int n, int left_cnt, int right_cnt, string sep) {
        if (left_cnt == n && right_cnt == n) 
        {
            ans.push_back(sep);
            return;
        }
        else {
            if (left_cnt < n) 
                dfs(n, left_cnt+1, right_cnt, sep + '(');
            if (right_cnt < n && left_cnt > right_cnt) 
                dfs(n, left_cnt, right_cnt+1, sep + ')');
        }
    }
};

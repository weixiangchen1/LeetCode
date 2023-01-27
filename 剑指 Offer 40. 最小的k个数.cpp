class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> ans;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto& x : arr) {
            pq.push(x);
        }
        while (k--) {
            int x = pq.top();
            pq.pop();
            ans.push_back(x);
        }
        return ans;
    }
};

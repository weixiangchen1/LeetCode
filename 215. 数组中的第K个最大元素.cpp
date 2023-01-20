class Solution {
public:
    int _findKthLargest(vector<int>& q, int l, int r, int k) {
        if (l == r) return q[l];
        
        int i = l - 1, j = r + 1, x = q[(l + r) >> 1];
        while (i < j) {
            do i++; while (q[i] > x);
            do j--; while (q[j] < x);
            if (i < j) swap(q[i], q[j]);
        }

        int sl = j - l + 1;
        if (sl >= k) return _findKthLargest(q, l, j, k);
        return _findKthLargest(q, j + 1, r, k - sl);
    }


    int findKthLargest(vector<int>& nums, int k) {
        return _findKthLargest(nums, 0, nums.size() - 1, k);
    }
};

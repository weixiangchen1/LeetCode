class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int tmp = 1;
        for (int i = digits.size() - 1; i >= 0; --i) {
            digits[i] += tmp;
            tmp = 0;
            if (digits[i] > 9) {
                tmp = digits[i] / 10;
                digits[i] %= 10;
            } 
        }
        if (tmp != 0) digits.insert(digits.begin(), 1);

        return digits;
    }
};

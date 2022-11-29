class Solution {
public:
    int minOperations(string s) {
        int cntA = 0, cntB = 0;
        for (int i = 0; i < s.size(); ++i) {
            if((s[i] - '0') ^ (i & 1)) cntA++;
            if(!((s[i] - '0') ^ (i & 1))) cntB++;
        }

        return min(cntA, cntB);
    }
};

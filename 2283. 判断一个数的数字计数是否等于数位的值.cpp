class Solution {
public:
    bool digitCount(string num) {
        int hash[100];
        memset(hash, 0, 100);
        for (int i = 0; i < num.size(); ++i) {
            hash[i] += num[i] - '0';
            hash[num[i] - '0']--;
        }

        bool flag = true;
        for (int i = 0; i < 10; ++i) {
            if (hash[i] != 0)
                flag = false;
        }

        return flag;
    }
};

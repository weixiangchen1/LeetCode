class Solution {
public:
    int myAtoi(string s) {
        // �������õ�ǰ���ո�
        int index = 0;
        while (index < s.size() && s[index] == ' ') 
            index++;
        if (index == s.size())
            return 0;

        // �ж�����
        int flag = 1;
        if (s[index] == '-') 
        {
            flag = -1;
            index++;
        }
        else if (s[index] == '+')
        {
            index++;
        }

        // ������
        long long res = 0;
        while (index <= s.size() && s[index] >= '0' && s[index] <= '9')
        {
            res = res * 10 + s[index] - '0';
            index++;
            if (res > INT_MAX) 
                break;
        }
        res *= flag;
        if (res >= INT_MAX) return INT_MAX;
        if (res <= INT_MIN) return INT_MIN;

        return res;
    }
};

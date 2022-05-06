class Solution {
public:
    int firstUniqChar(string s) {
        int countArr[26] = {0};

        for(int i=0; i<s.size(); i++)
        {
            countArr[s[i]-'a']++;
        }

        for(int j=0; j<s.size(); j++)
        {
            if(countArr[s[j]-'a'] == 1)
            {
                return j;
            }
        }

        return -1;
    }
};

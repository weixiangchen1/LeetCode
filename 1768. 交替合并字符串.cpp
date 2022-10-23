class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int index1, index2;
        string ans;
        while(word1[index1] && word2[index2])
        {
            ans += word1[index1];
            ans += word2[index2];
            index1++;
            index2++;
        }

        if(!word1[index1]){
            while(word2[index2])
            {
                ans += word2[index2];
                index2++;
            }
        }

        
        if(!word2[index2]){
            while(word1[index1])
            {
                ans += word1[index1];
                index1++;
            }
        }

        return ans;
    }
};

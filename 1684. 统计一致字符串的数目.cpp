class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char, int> heap;
        for(int i = 0; i < allowed.size(); ++i) {
            heap[allowed[i]]++;
        }
        int count = 0;
        for(int i = 0; i < words.size(); ++i) {
            int flag = 1;
            for(int j = 0; j < words[i].size(); ++j) {
                if(heap.count(words[i][j]) == 0) flag = 0;
            }

            if(flag) count++;
        }

        return count;
    }
};

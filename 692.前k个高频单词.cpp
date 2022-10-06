class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        // ͳ�ƴ���
        map<string, int> countMap;
        for(auto& str : words)
        {
            countMap[str]++;
        }

        // �������
        multimap<int, string, greater<int>> sortMap;
        for(auto& kv : countMap)
        {
            sortMap.insert(make_pair(kv.second, kv.first));
        }

        // Tok
        vector<string> ans;
        auto it = sortMap.begin();
        while(k--)
        {
            ans.push_back(it->second);
            it++;
        }

        return ans;
    }
};

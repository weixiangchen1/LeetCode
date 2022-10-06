class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        // 统计次数
        map<string, int> countMap;
        for(auto& str : words)
        {
            countMap[str]++;
        }

        // 排序次数
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

class Solution {
public:
    static bool comp(pair<int, string>& p1, pair<int, string>& p2){
        if(p1.first == p2.first)
            return p1.second < p2.second;
        
        return p1.first > p2.first;
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(auto word: words)
            mp[word]++;
        
        vector<pair<int, string>> pairs;
        
        for(auto mpp: mp)
            pairs.push_back({mpp.second, mpp.first});
        
        sort(pairs.begin(), pairs.end(), comp);
        
        vector<string> answer;
        
        for(int i = 0; i < k; i++)
            answer.push_back(pairs[i].second);
        
        return answer;
    }
};
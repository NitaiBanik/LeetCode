class WordFilter {
public:
    unordered_map<string, int>mp;
    
    WordFilter(vector<string>& words) {
        for(int i = 0; i < words.size(); i++){
            string prefix = "";
           for(int j = 0; j < words[i].size(); j++){
               prefix += words[i][j];
               string suffix = "";
               for(int k = words[i].size()-1; k >=0; k--){
                   suffix = words[i][k] + suffix;
                   mp[prefix + '|' + suffix] = i + 1;
               }
           }
        }
    }
    
    int f(string prefix, string suffix) {
        return mp[prefix + '|' + suffix] - 1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
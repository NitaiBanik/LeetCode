class Solution {
public:
    static bool comp(string& s1, string&s2){
        return s1.size() < s2.size();
    }
    
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), comp);
        
        set<string> wordsToAddEncodingList;
        
        for(auto word: words)
            wordsToAddEncodingList.insert(word);
        
        for(int i = 0; i < words.size(); i++){
            int sz = words[i].size();
            for(int k = 1; k < sz; k++){
                string suffixToRemove = words[i].substr(k);
                if(wordsToAddEncodingList.find(suffixToRemove) != wordsToAddEncodingList.end
                  ()){
                    wordsToAddEncodingList.erase(suffixToRemove);
                }
            }
        }
        
        int sz = 0;
        for(auto word: wordsToAddEncodingList )
            sz += word.size()  +1;
        
        return sz;
    }
};
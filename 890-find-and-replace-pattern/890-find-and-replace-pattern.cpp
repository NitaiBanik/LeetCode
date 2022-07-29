class Solution {
public:
    bool isMatchedPattern(string word, string pattern){
        map<char, char> mapWordWithPattern;
        map<char, char> mapPatternWithWord;
        
        for(int i = 0; i < word.size(); i++){
            char w = word[i];
            char p = pattern[i];
            
            if(mapWordWithPattern.find(w) == mapWordWithPattern.end())
                mapWordWithPattern[w] = p;
            
            if(mapPatternWithWord.find(p) == mapPatternWithWord.end())
                mapPatternWithWord[p] = w;
            
            if(p != mapWordWithPattern[w] || w != mapPatternWithWord[p])
                return false;
        }
        
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> vec;
        
        for(auto word: words){
            if(isMatchedPattern(word, pattern)){
                vec.push_back(word);
            }
        }
        
        return vec;
    }
};
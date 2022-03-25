class Solution {
public:
    bool isComplete(vector<int>& vec, vector<int>& vec1){
        bool isOk = true;
        for(int i = 0; i < 26; i++){
            if(vec[i] > vec1[i]){
                isOk = false;
                break;
            }
        }
        
        return isOk;
    }
                     
    void increaseFrequency(vector<int>& frequency, char ch){
        if(ch >= 'a' && ch <= 'z') frequency[ch - 'a']++;
        if(ch >= 'A' && ch <= 'Z') frequency[ch - 'A']++;
    }
    
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        
        vector<int>vec(26, 0);
        
        for(auto chr: licensePlate){
            increaseFrequency(vec, chr);
        }
        
        int mn = 1001;
        string ans = "";
        
        for(auto word: words){
            vector<int>vec1(26, 0);
            
            for(auto ch: word){
                increaseFrequency(vec1, ch);
            }
            
            bool isComplet = isComplete(vec, vec1);
            
            if(isComplet && (word.size() < mn)){
                mn = word.size();
                ans = word;
            }
        }
        
        return ans;
        
    }
};
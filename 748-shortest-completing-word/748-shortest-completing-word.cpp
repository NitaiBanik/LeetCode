class Solution {
public:
    bool isComplete(vector<int>& vec, vector<int>& vec1, int totalChars){
        bool isOk = true;
        for(int i = 0; i < totalChars; i++){
            if(vec[i] > vec1[i]){
                isOk = false;
                break;
            }
        }
        return isOk;
    }
    
    void resetFrequency(vector<int>& vec, int totalChars){
        for(int i = 0; i < totalChars; i++)
            vec[i] = 0;
    }
                     
    void increaseFrequency(vector<int>& frequency, char ch){
        if(ch >= 'a' && ch <= 'z') frequency[ch - 'a']++;
        if(ch >= 'A' && ch <= 'Z') frequency[ch - 'A']++;
    }
    
    void calculateFrequency(vector<int>&vec, string str){
        for(auto chr: str){
            increaseFrequency(vec, chr);
        }
    }
    
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        int totalChars = 26;
        vector<int>vec(totalChars, 0), vec1(totalChars, 0);
        
        calculateFrequency(vec, licensePlate);
        
        int mn = 1001;
        string ans = "";
        
        for(auto word: words){
            calculateFrequency(vec1, word);
            
            bool isComplet = isComplete(vec, vec1, totalChars);
            
            if(isComplet && (word.size() < mn)){
                mn = word.size();
                ans = word;
            }
            
            resetFrequency(vec1, totalChars);
        }
        
        return ans;
        
    }
};
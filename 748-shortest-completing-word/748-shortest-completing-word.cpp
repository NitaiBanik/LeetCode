class Solution {
public:
    bool isComplete(vector<int>& vec, vector<int>& vec1){
        bool isOk = true;
        for(int i = 0; i < 26; i++){
            if(vec[i] > vec1[i]){
                isOk = false;
                break;
            }
            
            vec1[i] = 0;
        }
        for(int i = 0; i < 26; i++)
            vec1[i] = 0;
        return isOk;
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
        
       vector<int>vec(26, 0);
       vector<int>vec1(26, 0);
        
       calculateFrequency(vec, licensePlate);
        
        int mn = 1001;
        string ans = "";
        
        for(auto word: words){
            calculateFrequency(vec1, word);
            
            bool isComplet = isComplete(vec, vec1);
            
            if(isComplet && (word.size() < mn)){
                mn = word.size();
                ans = word;
            }
        }
        
        return ans;
        
    }
};
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        vector<int> frequency(26, 0);
        vector<string>answer;
        
        for(auto word: words2){
            vector<int> temporaryFrequency(26, 0);
            for(auto chr: word)
                temporaryFrequency[chr-'a']++;
            
            for(auto chr: word)
                frequency[chr-'a'] = max(frequency[chr-'a'], temporaryFrequency[chr-'a']);
        }
        
        
        for(auto word: words1){
            vector<int> temporaryFrequency(26, 0);
            
            for(auto chr: word)
                temporaryFrequency[chr-'a']++; 
            
            bool flag = true;
            
            for(auto chr = 'a'; chr <= 'z'; chr++){
               if(frequency[chr-'a'] > temporaryFrequency[chr-'a']){
                   flag = false;
                   break;
               }
            }
            
            if(flag)
                answer.push_back(word);
        }
        return answer;
    }
};
class Solution {
public:
    int getExistingLetterAsBits(string word){
        int value = 0;
        for(int i = 0; i < word.size(); i++)
            value|= (1 << (word[i]-'a'));
        
        return value;
    }
    
    int maxProduct(vector<string>& words) {
        vector<int> existingLetters(words.size(), 0);
        vector<int> length(words.size(), 0);
        
         for(int i = 0; i < words.size(); i++){
            existingLetters[i] = getExistingLetterAsBits(words[i]);
             length[i] = words[i].size();
         }

        int mx = 0;
        
        for(int i = 0; i < words.size(); i++){
            for(int j =  i + 1; j < words.size(); j++){
                int existingLetters2 = getExistingLetterAsBits(words[j]);
                
                if(existingLetters[i] & existingLetters[j]) continue;
        
                mx = max(mx, length[i] * length[j]);
            }
        }
        
        return mx;
        
    }
};
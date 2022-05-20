class Solution {
public:
    int lengthOfLastWord(string s) {     
        int wordLength = 0;
        
        for(int i = s.size() - 1; i >= 0; i--){
            if(s[i] != ' ')
                 wordLength++;
            
            if(s[i] == ' ' && wordLength > 0)
                break;
        }     
        return wordLength;
        
    }
};
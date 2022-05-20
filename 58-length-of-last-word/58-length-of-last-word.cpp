class Solution {
public:
    int lengthOfLastWord(string s) {     
        int wordLength = 0, isWordStarted = false;
        
        for(int i = s.size() - 1; i >= 0; i--){
            if(s[i] == ' ' && isWordStarted == true)
                break;
            
            if(s[i] != ' ')
                isWordStarted = true;
            
            if(isWordStarted) wordLength++;
        }     
        return wordLength;
        
    }
};
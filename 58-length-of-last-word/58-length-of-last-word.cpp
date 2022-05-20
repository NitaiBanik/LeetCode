class Solution {
public:
    int lengthOfLastWord(string s) {
        int last = s.size() - 1;  
        int cnt = 0, isFound = false;
        
        for(int i = last; i>=0; i--){
            if(s[i] == ' ' && isFound == true)
                break;
            if(s[i] != ' ')
                isFound = true;
            
            if(isFound) cnt++;
        }
        
        return cnt;
        
    }
};
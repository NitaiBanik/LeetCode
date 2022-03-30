class Solution {
public:
    bool isAlpah(char& ch){
        if(ch >= 'a' & ch <= 'z') return true;
        if(ch >= 'A' & ch <= 'Z') return true;
        else return false;
    }
    int lengthOfLastWord(string s) {
        int last = s.size() - 1;
        
        while(last >= 0 && !isAlpah(s[last]))
            last--;
        
        int cnt = 0;
        while(last >= 0 && isAlpah(s[last])){
            cnt++;
            last--;
        }
        
        return cnt;
        
    }
};
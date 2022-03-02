class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size() == 0) return true;
        
        int index = 0;
        
        for(auto chr: t)
            index += (chr == s[index] ? 1: 0);
        
        
        return index == s.size();
    }
};
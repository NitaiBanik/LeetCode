class Solution {
public:
    int removePalindromeSub(string s) {
        string ss = s;
        reverse(s.begin(), s.end());
        if(s == ss)
            return 1;
        return 2;
        
    }
};
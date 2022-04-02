class Solution {
public:
    bool fun(string& s, int left, int right, int operations){
        if(operations < 0) return false;
        if(left >= right) return true;
        
        if(s[left] == s[right]) 
            return fun(s, left + 1, right - 1, operations);
        
        return fun(s, left + 1, right, operations - 1)
            | fun(s, left, right - 1, operations - 1);
    }
    bool validPalindrome(string s) {
        return fun(s, 0, s.size() - 1, 1);
    }
};
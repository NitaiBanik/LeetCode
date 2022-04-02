class Solution {
public:
    bool isALphaNumeric(char& ch){
        if(ch >= 'A' && ch <= 'Z') return true;
        if(ch >= 'a' && ch <= 'z') return true;
        if(ch >= '0' && ch <= '9') return true;
        return false;
    }
    
    bool isSame(char& l, char& r){
     
      if(l == r)
          return true;
      else if((l >= '0' && l <= '9') || (r >= '0' && r <= '9'))
            return false;
      else if((l - 'A') == (r - 'a'))
          return true;
        else if((l - 'a') == (r - 'A'))
          return true;
        return false;
    }
    
    bool fun(string& s, int l, int r){
        if(l >= r) return true;
        
        if(!isALphaNumeric(s[l]))
            return fun(s, l + 1, r);
        
        else if(!isALphaNumeric(s[r]))
            return fun(s, l, r - 1);
        else if(isSame(s[l], s[r]))
            return fun(s, l + 1, r - 1);
        else return false;
    }
    bool isPalindrome(string s) {
        return fun(s, 0, s.size() -1);
    }
};
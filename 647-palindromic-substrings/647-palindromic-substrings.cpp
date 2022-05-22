class Solution {
public:
    bool isPalindrome(string str){
        int ln = str.size();
        for(int i = 0; i< ln / 2; i++){
            if(str[i] != str[ln - i - 1])
                return false;
        }
        return true;
    }
    int countSubstrings(string s) {
        int cnt = 0;
        for(int i = 0; i < s.size(); i++){
            string str = "";
            for(int j = i; j < s.size(); j++){
                str += s[j];
                if(isPalindrome(str)) cnt++;
            }
        }
        
        return cnt;
        
    }
};
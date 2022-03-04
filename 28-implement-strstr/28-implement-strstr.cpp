class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0;
        if(haystack.size() == 0 || (haystack.size() < needle.size())) return -1;
        
        for(int i = 0; i <= haystack.size() - needle.size(); i++){
            
            int found = true;
            for(int j = 0 ; j < needle.size(); j++){
                if(haystack[i + j] != needle[j]){
                      found = false;
                    break;
                }
            }
            
            if(found) return i;
            
        }
        
        return -1;
    }
};
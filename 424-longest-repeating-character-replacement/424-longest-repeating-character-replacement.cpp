class Solution {
public:  
    int characterReplacement(string s, int k) {
        int ans = 0;
       for(char i = 'A'; i <= 'Z'; i++){
           
           int left = 0, right = 0, otherChars = 0;
           while(left < s.size() && right < s.size()){
               if(s[right] != i) otherChars++;
               
               while(otherChars > k && left < s.size() && left <= right){
                   if(s[left] != i) otherChars--;
                   left++;
               }
               
               ans = max(ans, right - left + 1);
               right++;
           }  
       }
        return ans;
    }
};
    
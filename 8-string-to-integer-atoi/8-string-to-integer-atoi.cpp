class Solution {
public:
    int myAtoi(string s) {
        
        int beg = 0;
        while(beg < s.size()){
            if(s[beg] != ' ') break;
            beg++;
        }
        
        if(beg == s.size()) return 0;
        
        long long sign = 1;
        long long ans = 0;
        
        if(s[beg] == '+') beg++;
        else if(s[beg] == '-') {
            sign = -1;
            beg++;
        }
        
        if(beg == s.size()) return 0;
        
        
        while(beg < s.size())
        {
            if(s[beg] >= '0' && s[beg] <= '9') {
                ans = ans * 10 + s[beg] - '0';
                
                    if(ans > (1LL << 31)) ans = 1L << 31;
                beg++;
            }
            else break;
        }
        
        if(sign > 0){
            if(ans >= (1LL << 31)) 
                ans = (1LL << 31) - 1;
        }
        else{
             if(ans > (1LL << 31)) 
                ans = (1LL << 31);
            ans *= -1LL;
        }
        
        return ans;
    }
};
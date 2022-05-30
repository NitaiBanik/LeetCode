class Solution {
public:
    int divide(int dividend, int divisor) {
        
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        int sign = dividend > 0 ^ divisor > 0 ? -1: 1;
        
        long divid = abs(dividend);
        long divsr = abs(divisor);
        long ans = 0;
        
        while(divid >= divsr)
        {
            long tm = divsr, m = 1;
            
            while(tm << 1 <= divid){
                tm <<= 1;
                m <<= 1;
            }
            
            divid -= tm;
            ans += m;
        }
        return ans * sign;
    }
};
class Solution {
public:
    bool isPowerOfFour(int n) {
       long long value = 1;
    
        while(value < n){
            value *= 4;
        }
        return value == n;
    }
};
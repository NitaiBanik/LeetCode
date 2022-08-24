class Solution {
public:
    bool isPowerOfThree(int n) {
        
      n = n == 0 ? 2 : n;
        while(n%3 == 0)
            n/=3;
        
        return n == 1;
    }
};
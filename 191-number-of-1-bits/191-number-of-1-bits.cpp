class Solution {
public:
    // n & (n - 1) flips the last 1's bit. We will count How many operations required to make n ---> 0
    int hammingWeight(uint32_t n) {
        
        int totalOnes = 0;
            
            while(n != 0){
                n = n & (n - 1);
                totalOnes++;
            }
        
        return totalOnes;
        
    }
};
class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool previousBit = n % 2;
        n/=2;
        
        while(n!=0){
            bool currentBit = n % 2;
            if(previousBit == currentBit)
                return false; 
            n /= 2;
            previousBit = currentBit;
        }
        return true;
    }
};
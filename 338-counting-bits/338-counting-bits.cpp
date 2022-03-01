class Solution {
public:
    /// This is a pattern problem. After simulating on pen and paper pattern can be easily found.
    /// If number is Even -> total ones of number, Ones[number] = Ones[number/2]
    /// If Odd-> total ones of number, Ones[number] = Ones[number - 1] + 1
    
    vector<int> countBits(int n) {
        
        vector<int>Ones(n + 1, 0);
        
        Ones[0] = 0;
        for(int number = 1 ; number <= n; number++){
           if(number%2 == 0) Ones[number] = Ones[number/2];
           else Ones[number] = Ones[number - 1] + 1;
        }
        
        return Ones;
    }
};
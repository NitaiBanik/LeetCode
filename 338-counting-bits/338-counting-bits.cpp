class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int>Ones(n + 1, 0);
        
        for(int i = 0 ; i <= n; i++){
            int numberOfOnes = 0;
            
            for(int bit = 0; bit <= 17; bit++){
                if(i & (1 << bit)) numberOfOnes++;
            }
            Ones[i] = numberOfOnes;
        }
        
        return Ones;
    }
};
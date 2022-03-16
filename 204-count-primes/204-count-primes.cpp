class Solution {
public:
    int countPrimes(int n) {
        vector<int> isPrime(n + 1, true);
        
        for(int i = 4; i <= n; i+=2) isPrime[i] = false;
        
        int sq = sqrt(n);
        
        for(int i = 3; i <= sq; i++){
            for(int j = i * i; j <= n; j+=(2 * i))
                isPrime[j] = false;
        }
        
        int tot = 0;
        for(int i = 2; i < n; i++) tot += isPrime[i];
        
        return tot;
    }
};
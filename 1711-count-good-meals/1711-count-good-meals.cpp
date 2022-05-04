class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        int ans = 0;
        
        map<int, int> frequency;
        
        for(int i = 0; i < deliciousness.size(); i++){
            
            for(int j = 1; j <= (1<<22); j *= 2){
               int need = j - deliciousness[i];
                
                ans += frequency[need];
                ans %= 1000000007;
            }
            frequency[deliciousness[i]]++;
            
        }
        
        return ans;
    }
};
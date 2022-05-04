class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        long long ans = 0;
        
        map<int, int> frequency;
        
        for(int i = 0; i < deliciousness.size(); i++){
            
            for(int j = 1; j <= (1<<22); j *= 2){
               int need = j - deliciousness[i];
                
                ans += frequency[need];
            }
            frequency[deliciousness[i]]++;
            
        }
        
        return ans% 1000000007;
    }
};
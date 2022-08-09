class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int mod = 1e9+7;
        vector<long long> dp(arr.size(), 1LL);
        
        sort(arr.begin(), arr.end());
        
        unordered_map<int, int> valueWithIndex;
        
        for(int i = 0; i < arr.size(); i++)
            valueWithIndex[arr[i]] = i;
        
        for(int i = 0; i <arr.size(); i++){
            for(int j = 0; j < i; j++){
                if(arr[i] % arr[j] != 0) continue;
                int need = arr[i] / arr[j];
                if(valueWithIndex.count(need))
                    dp[i] = (dp[i] + (dp[j] * dp[valueWithIndex[need]])) % mod;
            }
        }
        
        long long answer = 0;
        
        for(auto val: dp){
            answer += val;
            answer %= mod;
        }
        
        return answer;
    }
};
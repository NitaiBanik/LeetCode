class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int mod = 1000000000 + 7;
        vector<int>vec(301, 0);
        
        for(auto val: arr)
            vec[val]++;
        long long ans = 0;
        
        for(int i = 0; i < arr.size() - 2; i++){
            vec[arr[i]]--;
            int pos = i + 1;
            for(int j = i + 1; j < arr.size() -1; j++){
                vec[arr[j]]--;
                pos = j;
                
                int need = target - (arr[i] + arr[j]);
                if(need < 0) break;
                ans += vec[need];
                if(ans >= mod)
                ans %= mod;
            }
            
            for(int j = i + 1; j <= pos; j++)
                vec[arr[j]]++;
        }
        return ans;
    }
};
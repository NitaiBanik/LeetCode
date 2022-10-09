class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<pair<int, int>> ple, nle;
        
        vector<int> left(arr.size()), right(arr.size());
        
        for(int i = 0; i < arr.size(); i++) 
           left[i] = i + 1, right[i] = arr.size() - i;
        
        for(int i = 0; i < arr.size(); i++){
            while(!ple.empty() && ple.top().first > arr[i])
                ple.pop();
            left[i] = ple.empty() ? i + 1: i - ple.top().second;
            ple.push({arr[i], i});
            
            while(!nle.empty() && nle.top().first > arr[i]){
                int pos = nle.top().second;
                nle.pop();
                
                right[pos] = i - pos; 
            }
            
            nle.push({arr[i], i});
        }
        
        long long ans = 0, mod = 1e9 + 7;
        
        for(int i = 0; i < arr.size(); i++)
            ans = (ans + (long long)left[i] * (long long)right[i] * (long long)arr[i]) % mod;
        
        return ans;
    }
};
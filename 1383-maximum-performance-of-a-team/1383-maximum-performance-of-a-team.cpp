class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> efficiencyWithSpeeds;
        
        for(int i = 0; i < n; i++){
            efficiencyWithSpeeds.push_back({efficiency[i], speed[i]});
        }
        
        sort(efficiencyWithSpeeds.rbegin(), efficiencyWithSpeeds.rend());
        
        priority_queue<int, vector<int>, greater<int>> speeds;
        
        long long mx = 0;
        long long sum = 0;
        
        for(auto efficiencyWithSpeed: efficiencyWithSpeeds){
            sum += efficiencyWithSpeed.second;
            
            speeds.push(efficiencyWithSpeed.second);
            
            if(speeds.size() > k){
                sum -= speeds.top();
                speeds.pop();
            }
            
            mx = max(mx, sum * efficiencyWithSpeed.first);
        }
        
        return mx % 1000000007;    
    }
};
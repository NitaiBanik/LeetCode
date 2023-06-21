class Solution {
public:
    pair<long long, long long> getAns(long long mid1, long long mid2, vector<int>& nums, vector<int>& cost){
        long long tot1 = 0LL, tot2 = 0LL;
        
        for(int i = 0; i < nums.size(); i++){
            tot1 += (abs(mid1 - nums[i]) * cost[i] * 1LL);
            tot2 += (abs(mid2 - nums[i]) * cost[i] * 1LL);
        }
        
        return {tot1, tot2};
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long lo = 1LL, hi = 1000000LL, ans1 = 0LL, ans2 = 0LL;
        
        while(lo <= hi){
            long long mid = (lo + hi) / 2LL;
            auto ans = getAns(mid, mid+1, nums, cost);
            ans1 = ans.first;
            ans2 = ans.second;
            
            if(ans1 > ans2){
                lo = mid + 1;
            }else{
                hi = mid - 1;
            }
        }
        
        return min(ans1, ans2);
    }
};
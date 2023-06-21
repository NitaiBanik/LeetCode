class Solution {
public:
    long long getAns(long long mid, vector<int>& nums, vector<int>& cost){
        long long tot = 0LL;
        
        for(int i = 0; i < nums.size(); i++){
            tot += (abs(mid - nums[i]) * cost[i] * 1LL);
        }
        
        return tot;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long lo = 1LL, hi = 1000000LL;
        
        while(lo <= hi){
            long long mid = (lo + hi) / 2.00;
            long long ans1 = getAns(mid, nums, cost);
            long long ans2 = getAns(mid + 1, nums, cost);
            
            if(ans1 > ans2){
                lo = mid + 1;
            }else{
                hi = mid - 1;
            }
        }
        
        return getAns(lo, nums, cost);
    }
};
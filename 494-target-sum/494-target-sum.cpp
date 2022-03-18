class Solution {
public:
    map<pair<int,int>, int>mp;
    int ways(vector<int>& nums, int pos, int target){
        if(pos == nums.size()){
            if(target == 0) return 1;
            return 0;
        }
        if(mp.find({pos, target}) != mp.end()) return mp[{pos, target}];
        
        return mp[{pos, target}] = ways(nums, pos + 1, target - nums[pos])
            +  ways(nums, pos + 1, target + nums[pos]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return ways(nums, 0, target);
    }
};
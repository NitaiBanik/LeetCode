class Solution {
public:
    int ways(vector<int>& nums, int pos, int target, map<pair<int,int>, int> &mp){
        if(pos == nums.size()){
            if(target == 0) return 1;
            return 0;
        }
        if(mp.find({pos, target}) != mp.end()) return mp[{pos, target}];
        
        return mp[{pos, target}] = ways(nums, pos + 1, target - nums[pos], mp)
            +  ways(nums, pos + 1, target + nums[pos], mp);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        map<pair<int,int>, int>mp;
        return ways(nums, 0, target, mp);
    }
};
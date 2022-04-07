class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        
        int sum = 0, cnt = 0;
        unordered_map<int, bool>mp;
        mp[0] = true;
        for(int i = 0; i < nums.size(); i++){
            sum  += nums[i];
            
            if(mp.find(sum - target) != mp.end()){
                cnt++;
                mp.clear();
                sum = 0;
            }
           mp[sum] = true;
        }
        return cnt;
    }
};
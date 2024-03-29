class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> previousPosition;
        
        for(int i = 0; i < nums.size(); i++){
            if(previousPosition.find(nums[i]) != previousPosition.end()){
                if(i - previousPosition[nums[i]] <= k) return true;
            }
            previousPosition[nums[i]] = i;
        }
        
        return false;
    }
};
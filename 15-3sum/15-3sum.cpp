class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        if(nums.size() < 3) return {};
        set<vector<int>>setOfAnswer;
        vector<vector<int>>ans;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size() - 2; i++){
            int need = -nums[i];
            
            int start = i + 1, end = nums.size() -1;
            
            while(start < end){
                int currentSum = nums[start] + nums[end];
                if(currentSum == need){
                    setOfAnswer.insert({nums[i], nums[start], nums[end]});
                    start++, end--;
                }
                else if(currentSum > need) end --;
                else start++;
            }
        }
        
        for(auto val: setOfAnswer)
            ans.push_back(val);
        return ans;
    }
};
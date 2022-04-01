class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        if(nums.size() < 3) return {};
        
        vector<vector<int>>setOfAnswer;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size() - 2; i++){
            int need = -nums[i];
            
            int start = i + 1, end = nums.size() -1;
            
            while(start < end){
                int currentSum = nums[start] + nums[end];
                
                if(currentSum == need){
                    setOfAnswer.push_back({nums[i], nums[start], nums[end]});
                    
                    int l = nums[start], r = nums[end];
                    while((nums[start] == l) && start < end)
                        start++;
                    
                     while((nums[end] == r) && start < end)
                         end--;
                }
                
                else if(currentSum > need) end--;
                else start++;
            }
            
            int val = nums[i];
            while((i + 1 < nums.size()) && (val == nums[i + 1]))
                i++;
        }
        
        return setOfAnswer;
    }
};
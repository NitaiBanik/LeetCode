class Solution {
public:
    bool isvalidIndex(int index, vector<int>& nums, int val){
        return index >= 0 && index < nums.size() && nums[index] == val;
    }
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
                    while(isvalidIndex(start + 1, nums, l))
                        start++;
                    
                     while(isvalidIndex(end -1, nums, r))
                         end--;
                    
                    start++, end--;
                }
                
                else if(currentSum > need) end--;
                else start++;
            }
            
            int val = nums[i];
            while(isvalidIndex(i + 1, nums, val))
                i++;
        }
        
        return setOfAnswer;
    }
};
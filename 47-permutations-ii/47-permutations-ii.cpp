class Solution {
public:
    vector<int> nextPermutation(vector<int>& nums){
        if(nums.size() < 2) return {};
        
        int lf = -1;
        
        for(int i = nums.size() - 1; i> 0; i--){
            if(nums[i] > nums[i-1]){
                lf = i - 1;
                break;
            }
        }
        
        if(lf == -1) return {};
        sort(nums.begin() + lf + 1,nums.end());
        
        for(int i = lf + 1; i < nums.size(); i++){
            if(nums[i] > nums[lf]){
                swap(nums[i], nums[lf]);
                break;
            }
        }
        
        return nums;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<vector<int>> answer;
        
        sort(nums.begin(), nums.end());
        
        while(1){
            answer.push_back(nums);
            nums = nextPermutation(nums);
            if(nums.size() == 0) break;
        }
        return answer;
    }
};
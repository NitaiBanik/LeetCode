class Solution {
public:
     bool nextPermutation(vector<int>& nums) {
        
        if(nums.size() < 2) return false;
        
        int lf = -1;
        int rt = nums.size() - 1;
        for(int i = nums.size() - 1; i > 0; i--){
            if(nums[i] > nums[i - 1])
            {
                lf = i - 1;
                break;
            }
        }
         
        if(lf == -1) return false;
        sort(nums.begin() + lf + 1, nums.end());
        if(lf != -1){
            for(int i = lf + 1; i <= rt; i++){
                if(nums[i] > nums[lf])
                {
                    rt = i; 
                    break;
                }
            }
            swap(nums[lf], nums[rt]);
        }
        return true;
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        while(1){
         ans.push_back(nums);
           bool isExists = nextPermutation(nums);
            if(!isExists)
               break;
        }
        
        return ans;
    }
};
class Solution {
public:
    
    
    void generate(int mask, vector<int>& nums, vector<int>& permutation, vector<vector<int>>& allPermutation){
        
        if(mask == (1<<nums.size())-1){
            allPermutation.push_back(permutation);
            return;
        }
        
        for(int i = 0; i < nums.size(); i++){
            if((mask & (1<<i)) == 0){
                permutation.push_back(nums[i]);
                generate(mask | (1<<i), nums, permutation, allPermutation);
                permutation.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> allPermutation;
        vector<int> permutation;
        generate(0, nums, permutation, allPermutation);
        return allPermutation;
    }
};
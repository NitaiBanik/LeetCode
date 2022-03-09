class Solution {
public:
    vector<int> permutation;
    vector<vector<int>> allPermutation;
    
    void generate(int mask, vector<int>& nums){
        
        if(mask == (1<<nums.size())-1){
            allPermutation.push_back(permutation);
        }
        for(int i = 0; i < nums.size(); i++){
            if((mask & (1<<i)) == 0){
                permutation.push_back(nums[i]);
                generate(mask | (1<<i), nums);
                permutation.pop_back();
            }
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        generate(0, nums);
        return allPermutation;
        
    }
};
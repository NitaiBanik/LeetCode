class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>vec(nums.size() + 1, 0);
        
        for(auto num: nums){
            vec[num]++;
        }
        
        int duplicate = -1, notExist = -1;
        for(int i = 1; i <= nums.size(); i++){
            if(vec[i] > 1) duplicate = i;
            if(vec[i] == 0) notExist = i;
        }
        
        return {duplicate, notExist};
    }
};
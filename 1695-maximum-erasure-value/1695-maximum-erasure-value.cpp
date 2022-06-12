class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        vector<bool>frequency(10001, false);
        int sum = 0, lf = 0, mx = 0;
        
        for(int i = 0; i < nums.size(); i++){
            while(frequency[nums[i]] == true){
                frequency[nums[lf]] = false;
                sum-= nums[lf++];
            }
             sum+= nums[i];
            frequency[nums[i]] = true;
            mx = max(mx, sum);
        }
        return mx;
    }
};
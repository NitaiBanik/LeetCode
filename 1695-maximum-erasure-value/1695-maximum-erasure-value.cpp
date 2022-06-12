class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        map<int, int>frequency;
        int sum = 0, lf = 0, mx = 0;
        
        for(int i = 0; i < nums.size(); i++){
            sum+= nums[i];
            frequency[nums[i]]++;
            
            while(frequency[nums[i]] > 1){
                frequency[nums[lf]]--;
                sum-= nums[lf++];
            }
            mx = max(mx, sum);
        }
        return mx;
    }
};
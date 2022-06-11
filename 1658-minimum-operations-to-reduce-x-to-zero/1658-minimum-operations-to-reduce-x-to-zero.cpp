class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int lf = 0;
        long sum = 0, curr = 0;
        int mn = 0;
        
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
      
        sum = sum - x;
        if(sum == 0) return nums.size();   
        if(sum < 0) return -1;
        
        for(int i = 0; i < nums.size(); i++)
        {
            curr += nums[i];
            while(curr > sum)
                curr -= nums[lf++];
            if(curr == sum)
                mn = max(mn, i - lf + 1);
        }    
        
      return mn == 0 ? -1: nums.size() - mn; 
    }
};
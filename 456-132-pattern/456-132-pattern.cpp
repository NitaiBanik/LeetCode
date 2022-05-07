class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        int thirdValue = INT_MIN;
        stack<int> stak;
        
        for(int i = nums.size() - 1; i >= 0; i--){
            if(nums[i] < thirdValue) return true;
            
            while(!stak.empty() && stak.top() < nums[i]){
                thirdValue = stak.top();
                stak.pop();
            }
            stak.push(nums[i]);
        }
        
        return false;
        
    }
};
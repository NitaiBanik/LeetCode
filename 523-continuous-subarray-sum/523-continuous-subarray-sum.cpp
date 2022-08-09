class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> previousReminders;
        
        int sum = 0;
        previousReminders[0] = -1;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];      
            if(k!=0)sum %= k;
            
            if(previousReminders.find(sum) != previousReminders.end()){
            if(i - previousReminders[sum] > 1){
                return true;
            }
            }
            else
            previousReminders[sum] = i;
        }
        return false;
    }
};
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        int oddPosition = 0;
        
        while(oddPosition < nums.size()){
            while(oddPosition <nums.size() &&  nums[oddPosition]%2 == 0) oddPosition++;
            
            int evenPosition = oddPosition + 1; 
            while(evenPosition <nums.size() &&  nums[evenPosition]%2 == 1) evenPosition++;
            
            if(oddPosition >= nums.size() || evenPosition >= nums.size())
                break;
            swap(nums[oddPosition], nums[evenPosition]);
            oddPosition++;
            
        }
        
        return nums;
        
    }
};
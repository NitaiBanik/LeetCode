class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        vector<int>leftMin(nums.size(), 0);
        int mnLeft = nums[0];
        
        for(int i = 0; i < nums.size(); i++){
            leftMin[i] = mnLeft;
            mnLeft = min(mnLeft, nums[i]);
        }
        
        stack<int> valuesGreaterThanMin;      
        for(int i = nums.size() - 1; i > 0; i--){
            
            while(!valuesGreaterThanMin.empty() && valuesGreaterThanMin.top() <= leftMin[i])
                valuesGreaterThanMin.pop();
            
            if(!valuesGreaterThanMin.empty() && valuesGreaterThanMin.top() < nums[i])
                 return true;
            
            valuesGreaterThanMin.push(nums[i]);
        }
        
        return false;
        
    }
};
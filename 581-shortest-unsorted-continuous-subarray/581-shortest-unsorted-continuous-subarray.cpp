class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int begin = nums.size(), end = 0;
        
        stack<int>positions;
        
        for(int i = 0; i < nums.size(); i++){
            while(!positions.empty() && nums[positions.top()] > nums[i]){
                begin = min(begin, positions.top());
                positions.pop();
            }
            positions.push(i);
        }
        
        while(!positions.empty())
            positions.pop();
        
        for(int i = nums.size() -1; i >= 0; i--){
            while(!positions.empty() && nums[positions.top()] < nums[i]){
                end = max(end, positions.top());
                positions.pop();
            }
            positions.push(i);
        }
        
        return end-begin >= 0 ? end - begin + 1 : 0;
        
    }
};
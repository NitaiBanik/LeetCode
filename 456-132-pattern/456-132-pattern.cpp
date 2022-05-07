class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        vector<int>leftMin(nums.size(), 0);
        set<long long>stt;
        
        int mnLeft = INT_MAX, mnRight = INT_MAX;
        
        for(int i = 0, j = nums.size() - 1; i < nums.size(); i++, j--){
            leftMin[i] = mnLeft;
         //   rightMin[j] = mnRight;
            mnLeft = min(mnLeft, nums[i]);
         //   mnRight = min(mnRight, nums[j]);
        }
        
        for(int i = nums.size() -1; i >= 0; i--){
            auto lowerBound = stt.lower_bound((long long)leftMin[i] + 1);
            
            if(lowerBound != stt.end() && leftMin[i] < nums[i] && nums[i] > *lowerBound)
                return true;
            stt.insert(nums[i]);
        }
        
        return false;
        
    }
};
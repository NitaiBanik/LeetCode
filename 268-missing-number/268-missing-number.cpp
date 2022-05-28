class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xorr = 0;
        for(int i= 0 ; i <= nums.size(); i++)
            xorr ^= i;
        
        for(auto x: nums)
            xorr^=x;
        
        return xorr;
    }
};
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        map<int, int> suffix;
        int sum = 0, mn = 999999999;
        
        for(int i = 0 ; i < nums.size(); i++)
        {
            sum += nums[i];
            suffix[sum] = i + 1;
            if(sum == x)
                 mn = min(mn, i+1);
                
        }
        sum = 0;
        for(int i = nums.size() - 1; i >=0; i--){
            sum += nums[i];
            if(sum == x)
                mn = min(mn, (int)nums.size() - i);
            
            if(suffix[x- sum] > 0 && i + 1 > suffix[x- sum] )
                mn = min(mn, suffix[x - sum] + (int)nums.size() - i);
        }
        return mn == 999999999 ? -1: mn;
    }
    
};
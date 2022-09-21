class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        vector<int>sums(queries.size(), 0);
        
        int evenSum = 0;
        for(auto num: nums){
            if((num&1) == 0)
                evenSum += num;
        }
        int id = 0;
        for(auto query: queries){
            int value = query[0];
            int index = query[1];
            
            int numIndexValue = nums[index];
            int ans = evenSum;
            
            if((numIndexValue&1) == 0) ans -= numIndexValue;
            
            numIndexValue += value;
            
             if((numIndexValue&1) == 0) ans += numIndexValue;
            
            evenSum = ans;
            nums[index] = numIndexValue;
            
            sums[id++] = ans;
        }
        
        return sums;
    }
};
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        map<int, int> frequencyOfNumber;
        frequencyOfNumber[0] = 1;
        
        int sum = 0, count = 0;
        
        for(auto num: nums){
            sum += num;
            count += (frequencyOfNumber[sum - k]);
            
            frequencyOfNumber[sum]++;
        }
        return count;
    }
};
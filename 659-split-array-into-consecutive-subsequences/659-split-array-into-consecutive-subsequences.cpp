class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> frequency, canBeAdded;
        
        for(auto num: nums)
            frequency[num]++;
        
        for(auto num: nums){
            if(frequency[num] <= 0) continue;
            if(canBeAdded[num] > 0){
                canBeAdded[num]--;
                frequency[num]--;
                canBeAdded[num + 1]++;
            }
            else if(frequency[num + 1] > 0 && frequency[num + 2] > 0){
                frequency[num]--;
                frequency[num + 1]--;
                frequency[num + 2]--;
                canBeAdded[num + 3]++;
            }
            else return false;
        }
        
        return true;
    }
};
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int>frequency;
        int answer = 0;
        
        for(auto num: nums){
            int need = k - num;
            
            if(frequency[need]>0){
                answer++;
                frequency[need]--;
            }
            else frequency[num]++;
        }
        
        return answer;
        
    }
};
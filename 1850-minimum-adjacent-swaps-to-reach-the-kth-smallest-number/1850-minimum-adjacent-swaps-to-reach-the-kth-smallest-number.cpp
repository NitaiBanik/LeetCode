class Solution {
public:
    int getMinSwaps(string num, int k) {
        string s = num;
        int swap_count = 0;
        while(k--){
           nextPermutation(num);
        }
        for(int i = 0 ; i < s.size(); i++){
            int j = i + 1;
            while(s[i] != num[i]){
                swap_count++;
                swap(num[i], num[j++]);
            }
        }
        return swap_count;
    }
    
    void nextPermutation(string& nums) {
        
        if(nums.size() < 2) return;
        
        int lf = -1;
        int rt = nums.size() - 1;
        for(int i = nums.size() - 1; i > 0; i--){
            if(nums[i] > nums[i - 1])
            {
                lf = i - 1;
                break;
            }
        }
        
        sort(nums.begin() + lf + 1, nums.end());
        if(lf != -1){
            for(int i = lf + 1; i <= rt; i++){
                if(nums[i] > nums[lf])
                {
                    rt = i; 
                    break;
                }
            }
            swap(nums[lf], nums[rt]);
        }
    }
};
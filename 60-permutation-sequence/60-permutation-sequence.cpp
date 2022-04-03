class Solution {
public:
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
    
    string getPermutation(int n, int k) {
        string nums = "";
        
        for(int i = 1; i <= n; i++){
            nums += char(i + '0');
        }
        k--;
        
        while(k--){
            nextPermutation(nums);
        }
        return nums;       
    }
};
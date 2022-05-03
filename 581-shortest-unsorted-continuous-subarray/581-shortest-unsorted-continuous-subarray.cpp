class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int mn = INT_MAX, mx = INT_MIN;
        bool found = false;
        
        for(int i = 1; i < nums.size(); i++){
            if(nums[i - 1] > nums[i]){
                found  = true;
            }           
            if(found)
                mn= min(mn, nums[i]);
                
        }
        
        found= false;
        
        for(int i = nums.size() - 2; i >= 0; i--){
            if(nums[i + 1] < nums[i]){
                found = true;
            }
            if(found)
                mx = max(mx, nums[i]);
        }
        
        int begin = 0, end = 0;
        
        for(begin = 0; begin < nums.size(); begin++)
            if(nums[begin] > mn) break;
        
        for(end = nums.size()-1; end >=0; end--)
            if(nums[end] < mx) break;
        
        //cout<<"begin = "<<begin<<" end = "<<end<<endl;
        
        return end-begin >= 0 ? end - begin + 1 : 0;
        
    }
};
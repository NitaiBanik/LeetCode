class Solution {
public:
    void nextPermutation(vector<int>& nums) {
       
        int leftIndex = -1, rightIndex = nums.size() - 1;
        
        for(int i = nums.size() - 2; i >= 0; i--){
            if(nums[i + 1] > nums[i]){
                leftIndex = i;
                break;
            }
        }
        
        if(leftIndex != -1){
            for(int i = nums.size() - 1; i >= 0; i--){
                if(nums[i] > nums[leftIndex]){
                    rightIndex = i;
                    break;
            }
        }
        int tmp = nums[leftIndex];
        nums[leftIndex] = nums[rightIndex];
        nums[rightIndex] = tmp;
        }

        int lastIndex = nums.size() - 1;
        
        cout<<"left = "<<leftIndex<<" right = "<<rightIndex<<endl;
        for(auto num: nums) cout<<num<<" ";
        cout<<endl;
        
        //if(leftIndex == 0 && rightIndex == nums.size()-1) return;
        
        cout<<"left = "<<leftIndex<<" right = "<<rightIndex<<endl;
            
        for(int i = leftIndex + 1; i < nums.size() && i < lastIndex; i++){
            int tmp = nums[lastIndex];
            nums[lastIndex] = nums[i];
            nums[i] = tmp;
            lastIndex--;
        }
        
    }
};
class Solution {
public:
    void swapValues(int index1, int index2, vector<int>& nums){
        int tmp = nums[index1]; 
        nums[index1] = nums[index2];
        nums[index2] = tmp;
    }
    
    int getLeftIndexToSwap(vector<int>& nums){
        int leftIndex = -1;
        for(int i = nums.size() - 2; i >= 0; i--){
            if(nums[i + 1] > nums[i]){
                leftIndex = i;
                break;
            }
        }
        
        return leftIndex;
    }
    
    int getRightIndexToSwap(vector<int>& nums, int leftIndex){
        int rightIndex = nums.size() - 1;
        for(int i = nums.size() - 1; i >= 0; i--){
            if(nums[i] > nums[leftIndex]){
                rightIndex = i;
                break;
            }
        }
        return rightIndex;
    }
    
    void nextPermutation(vector<int>& nums) { 
        int leftIndex = getLeftIndexToSwap(nums);
        int rightIndex = nums.size() - 1;
        
        if(leftIndex != -1){
            rightIndex = getRightIndexToSwap(nums, leftIndex);
            swapValues(leftIndex, rightIndex, nums);
        }

        int lastIndex = nums.size() - 1;  
        leftIndex++;
        while(leftIndex < nums.size() && leftIndex < lastIndex){
            swapValues(leftIndex, lastIndex, nums);
            leftIndex++;
            lastIndex--;
        }
        
    }
};
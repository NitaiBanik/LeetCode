public class Solution {
    public int PivotIndex(int[] nums) {
        int totalSum = 0;
        foreach(var num in nums)
            totalSum += num;
        
        int currentSum = 0;
        for(int i = 0 ; i < (int)nums.Count(); i++){
            if(currentSum == (totalSum - currentSum - nums[i]))
                return i;
             currentSum += nums[i];
        }
        
        return -1;
    }
}
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        
        int numberOfSteps = 0;
        while(target > startValue){
            
            if(target%2) target++;
            else target /= 2;
            
            numberOfSteps++;
        }
        
        return numberOfSteps + (startValue - target);
        
    }
};
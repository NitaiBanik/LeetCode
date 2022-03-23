class Solution {
public:
    int brokenCalc(int startValue, int target) {
        
        int numberOfSteps = 0;
        
        while(startValue != target){
            
            if(target%2 == 0 && startValue < target){
                numberOfSteps++;
                target/=2;
            }
            else if(target < startValue)
                return numberOfSteps + (startValue -  target);
            else {
                target++;
                numberOfSteps++;
            }
            
        }
        return numberOfSteps;
        
    }
};
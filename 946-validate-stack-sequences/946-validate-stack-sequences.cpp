class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        int popIdx = 0, pushIdx = 0;
        
        for(auto val: pushed){
            pushed[pushIdx] = val;
            while(pushIdx >=0 &&  pushed[pushIdx] == popped[popIdx]){
                pushIdx--;
                popIdx++;
            }
            pushIdx++;
        }
        
        return pushIdx == 0;  
    }
};
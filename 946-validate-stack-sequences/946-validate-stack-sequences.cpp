class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        int popIdx = 0, pushIdx = 0;
        
        for(int i = 0; i < pushed.size(); i++){
            pushed[pushIdx] = pushed[i];
            while(pushIdx >=0 &&  pushed[pushIdx] == popped[popIdx]){
                pushIdx--;
                popIdx++;
            }
            pushIdx++;
        }
        
        return pushIdx == 0;  
    }
};
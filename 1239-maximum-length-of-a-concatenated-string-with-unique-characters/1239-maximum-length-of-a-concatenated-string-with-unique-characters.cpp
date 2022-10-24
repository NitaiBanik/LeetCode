class Solution {
public:
    int isPossibleToTake(vector<string>& arr, int value){
        vector<bool> takenChars(130, false);
        int cnt = 0;
        
        for(int i = 0; i < arr.size(); i++){
            if(value & (1<<i)){
                for(int j = 0; j < arr[i].size(); j++){
                    if(takenChars[arr[i][j]]) return 0;
                    
                    takenChars[arr[i][j]]= true;
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
    
    int maxLength(vector<string>& arr) {
        int possibleWays = (1 << arr.size());
        int answer = 0;
        
        for(int i = 0; i < possibleWays; i++){
            int pp = isPossibleToTake(arr, i);
            answer = max(pp, answer);
        }
        return answer;
    }
};
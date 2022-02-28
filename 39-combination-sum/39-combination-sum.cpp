class Solution {
public:
    vector<vector<int>> combinations;
    
    void coinChange(int pos, int target, vector<int>& coins, vector<int>& currentCoins){
        
        if(target == 0){
            combinations.push_back(currentCoins);
            return;
        }
        
        if(target < 0 || pos == coins.size()) return;
        
        vector<int> temp = currentCoins;
        int tempTarget = target;
        
       for(int i = 1;;i++){
           
           tempTarget-= coins[pos];
           if(tempTarget < 0) break;
           temp.push_back(coins[pos]);
        coinChange(pos + 1, tempTarget, coins, temp);
       }
        
        coinChange(pos + 1, target, coins, currentCoins);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> currentCoins;
        coinChange(0, target, candidates, currentCoins);
        return combinations;
    }
};
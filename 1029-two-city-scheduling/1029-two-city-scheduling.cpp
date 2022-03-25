class Solution {
public:
    int dp[101][51][51];
    int fun(vector<vector<int>>& costs, int index, int group1, int group2){
        if(index == costs.size()) return 0;
        if(dp[index][group1][group2] != -1) return dp[index][group1][group2];
        
        if(group2 == 0)  return dp[index][group1][group2] = costs[index][0] + fun(costs, index + 1, group1 - 1, 0);
        if(group1 == 0)  return dp[index][group1][group2] = costs[index][1] + fun(costs, index + 1, 0, group2 - 1);
        else return dp[index][group1][group2] =  min(costs[index][0] + fun(costs, index + 1, group1 - 1, group2), costs[index][1] + fun(costs, index + 1, group1, group2 - 1));
        
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        memset(dp, -1, sizeof(dp));
        
        return fun(costs, 0, costs.size() / 2, costs.size() / 2);
    }
};
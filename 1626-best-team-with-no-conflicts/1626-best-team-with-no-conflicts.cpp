class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> ageWithScores(scores.size());
        vector<int>ans(scores.size(), 0);
        
        for(int i = 0; i < scores.size(); i++){
            ageWithScores[i] = {ages[i], scores[i]};
        }
        
        sort(ageWithScores.begin(), ageWithScores.end());
        int result = 0;
        
        for(int i = 0; i < scores.size(); i++){
            ans[i] = ageWithScores[i].second;
            
            for(int j = i - 1; j >= 0; j--){
                if(ageWithScores[j].second <= ageWithScores[i].second)
                    ans[i] = max(ans[i], ageWithScores[i].second + ans[j]);
            }
            
            result = max(result, ans[i]);
        }
        
        return result;
    }
};
class Solution {
public:
    void backTrack(int pos, int n, int k, vector<int>& current, vector<vector<int>>& ans){
        
        if(current.size() == k){
            ans.push_back(current);
            return;
        }
        
        for(int i = pos; i <= n; i++){
            current.push_back(i);
            backTrack(i + 1, n, k, current, ans);
            current.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>>ans;
        vector<int> current;
        
        backTrack(1, n, k, current, ans);
        
        return ans;
    }
};
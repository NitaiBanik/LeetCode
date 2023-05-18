class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>vec(n, 0);
        vector<int>ans;
        
        for(auto edge: edges){
            vec[edge[1]]++;
        }
        
        for(int i = 0; i < n; i++){
            if(!vec[i]) ans.push_back(i);
        }
        
        return ans;
    }
};
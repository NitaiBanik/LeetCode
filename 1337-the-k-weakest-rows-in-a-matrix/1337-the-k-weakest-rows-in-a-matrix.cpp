class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
         priority_queue<pair<int, int>>pq;
        
        for(int i = 0; i < mat.size(); i++){
            int soldier = 0;
            for(int j = 0; j < mat[0].size(); j++){
                soldier += mat[i][j];
            }
            
            pq.push({soldier, i});
            
            if(pq.size() > k) pq.pop();
        }
        
        vector<int>vec(k, 0);
        
        int idx = k-1;
        while(!pq.empty()){
            vec[idx--] = pq.top().second;
            pq.pop();
        }
        
        return vec;
    }
};
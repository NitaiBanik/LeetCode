class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(original.size() != (m * n)) return {};
        
        vector<vector<int>> vec(m, vector<int>(n));
        
        int row = 0, col = 0;
        
        for(int i = 0; i < original.size(); i++){
            vec[row][col++] = original[i];
            if(col == n) row++, col = 0;
        }
        
        return vec;
    }
};
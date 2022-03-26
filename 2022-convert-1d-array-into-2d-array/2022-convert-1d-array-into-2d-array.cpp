class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(original.size() != (m * n)) return {};
        
        vector<vector<int>> vec(m);
        
        for(int i = 0; i < original.size(); i++){
            vec[i/n].push_back(original[i]);
        }
        
        return vec;
    }
};
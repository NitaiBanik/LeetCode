class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        vector<vector<int>> answer(matrix.size());
        
        for(int col  = 0; col < matrix.size(); col++){
            for(int row = matrix.size() -1 ; row >= 0; row--){
                answer[col].push_back(matrix[row][col]);
            cout<<matrix[row][col]<< " ";}
            cout<<endl;
        }
        
        matrix = answer;
    }
};
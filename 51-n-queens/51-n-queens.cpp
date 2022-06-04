class Solution {
public:
    vector<vector<string>> ans;
    bool isValid(vector<string>& board, int row, int col){
        for(int i = row; i >= 0; i--)
            if(board[i][col] =='Q') return false;
        
        for(int i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if(board[i][j] =='Q') return false;
        
         for(int i = row, j = col; i >= 0 && j < board.size(); i--, j++)
            if(board[i][j] =='Q') return false;
        
        return true;
    }
    void solveBoard(vector<string> &board, int row){
        if(row == board.size()){
            ans.push_back(board);
            return;
        }
        
        for(int col = 0; col < board.size(); col++){
            if(isValid(board, row, col)){
                board[row][col] = 'Q';
                solveBoard(board, row + 1);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        solveBoard(board, 0);
        
    return ans;
    }
};
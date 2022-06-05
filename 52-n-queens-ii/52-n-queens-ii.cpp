class Solution {
public:

 int ans = 0;
    bool isValid(vector<vector<bool>>& board, int row, int col){
        for(int i = row; i >= 0; i--)
            if(board[i][col]) return false;
        
        for(int i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if(board[i][j]) return false;
        
         for(int i = row, j = col; i >= 0 && j < board.size(); i--, j++)
            if(board[i][j]) return false;
        
        return true;
    }
    void solveBoard(vector<vector<bool>> &board, int row){
        if(row == board.size()){
            ans++;
            return;
        }
        
        for(int col = 0; col < board.size(); col++){
            if(isValid(board, row, col)){
                board[row][col] = true;
                solveBoard(board, row + 1);
                board[row][col] = false;
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<bool>> board(n, vector<bool>(n, false));
        solveBoard(board, 0);
        
    return ans;
    }
};
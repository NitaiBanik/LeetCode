class Solution {
public:

    bool isValid(vector<vector<bool>>& board, int row, int col){
        for(int i = row; i >= 0; i--)
            if(board[i][col]) return false;
        
        for(int i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if(board[i][j]) return false;
        
         for(int i = row, j = col; i >= 0 && j < board.size(); i--, j++)
            if(board[i][j]) return false;
        
        return true;
    }
    int solveBoard(vector<vector<bool>> &board, int row){
        if(row == board.size()){
            return 1;
        }
        int ans = 0;
        for(int col = 0; col < board.size(); col++){
            if(isValid(board, row, col)){
                board[row][col] = true;
                ans += solveBoard(board, row + 1);
                board[row][col] = false;
            }
        }
        
        return ans;
    }
    int totalNQueens(int n) {
        vector<vector<bool>> board(n, vector<bool>(n, false));
        return solveBoard(board, 0);
    }
};
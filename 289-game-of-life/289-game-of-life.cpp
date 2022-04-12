class Solution {
public:
    int fx[8] = {0, 0, -1, +1, -1, -1, +1, +1};
    int fy[8] = {-1, +1, 0, 0, -1, +1, -1, +1};
    
    bool isValid(int x, int y, int r, int c){
        return (x >= 0 && x < r) &&  (y>=0 && y < c); 
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> newBoard(board.size(), vector<int>(board[0].size(), 0));
        
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                int totalZero = 0, totalOne = 0;
                for(int k = 0; k < 8; k++){
                    int p = i + fx[k], q = j + fy[k];
                    if(isValid(p, q, board.size(), board[0].size())){
                        if(board[p][q] == 0) totalZero++;
                        else totalOne++;
                    }
                }
               if(totalOne > 3) newBoard[i][j] = 0;
               else if(totalOne == 3) newBoard[i][j] = 1;
                else if(totalOne < 2) newBoard[i][j] = 0;
                else newBoard[i][j] = board[i][j];
                
            }
        }
        
        board = newBoard;
    }
};
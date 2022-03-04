class Solution {
public:
    bool isValidByRowAndCol(vector<vector<char>>& board){
        
        map<char, bool>row[10], col[10];
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++){
            if(board[i][j] != '.'){
                if(row[i].find(board[i][j]) != row[i].end())
                    return false;

                if(col[j].find(board[i][j]) != col[j].end())
                    return false;

                row[i][board[i][j]] = true;
                col[j][board[i][j]] = true;
            }
        }   
        return true;
    }
    
    bool isValidBySubBoxes(vector<vector<char>>& board){
        map<char, bool>mp1, mp2, mp3;
        
        for(int i = 0; i < 9; i++){
            
            for(int j = 0; j < 3; j++){
                if((board[i][j] != '.') && (mp1.find(board[i][j]) != mp1.end())){
                    return false;
                }
                mp1[board[i][j]] = true;
            }
            
            for(int j = 3; j < 6; j++){
                if((board[i][j] != '.') && (mp2.find(board[i][j]) != mp2.end())){
                    return false;        
                }
                mp2[board[i][j]] = true;
            }
            
            for(int j = 6; j < 9; j++){
                if((board[i][j] != '.') && (mp3.find(board[i][j]) != mp3.end())){
                    return false;        
                }
                 mp3[board[i][j]] = true;
            }
            if(i%3 == 2){
                mp1.clear(), mp2.clear(), mp3.clear();
            }  
        }
        return true;
    }
        
    bool isValidSudoku(vector<vector<char>>& board) {
        
        bool isValidbyRowColumn = isValidByRowAndCol(board);    
        if(!isValidbyRowColumn) return false;
        
        return isValidBySubBoxes(board);
    }
};
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        
        double tower[102][102]={0.0};
        
        tower[0][0] = (double)poured;
        
        for(int row = 0; row < 100; row++){
            for(int col = 0; col <= row; col++){
                double extra = (tower[row][col] - 1.0) / 2.00;
                if(extra > 0){
                    tower[row + 1][col] += extra;
                    tower[row + 1][col + 1] += extra;
                }
            }
            
        }
     return min(1.00, tower[query_row][query_glass]);  
    }
};
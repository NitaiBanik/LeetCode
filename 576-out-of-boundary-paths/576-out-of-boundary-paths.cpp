class Solution {
public:
    long long ways[51][51][51];
    long long mod = 1e9 + 7;
    long long calculatePaths(int m, int n, int maxMove, int startRow, int startColumn){
        if(startRow == m || startRow < 0 || startColumn == n || startColumn < 0)
            return 1;
        if(maxMove == 0)
            return 0;
        
        if(ways[startRow][startColumn][maxMove] != -1) 
            return ways[startRow][startColumn][maxMove];
        
        
        return ways[startRow][startColumn][maxMove] = (calculatePaths(m, n, maxMove-1, startRow - 1, startColumn)
            +  calculatePaths(m, n, maxMove-1, startRow + 1, startColumn)
            +  calculatePaths(m, n, maxMove-1, startRow, startColumn + 1)
            +  calculatePaths(m, n, maxMove-1, startRow, startColumn - 1)) % mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(ways, -1, sizeof(ways));     
        return calculatePaths(m, n, maxMove, startRow, startColumn);
    }
};
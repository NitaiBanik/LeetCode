class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int l = 0, hi = row * col - 1;
        
        while(l <= hi){
            int mid = (l + hi) / 2;
            if(matrix[mid / col][mid % col] == target) return true;
            if(matrix[mid / col][mid % col] < target)
                l = mid + 1;
            else hi = mid - 1;
        }
        
        return false;
    }
};
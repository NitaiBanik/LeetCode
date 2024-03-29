class Solution {
public:
    vector<vector<int>> answers;
    void fun(int k, int n, int usedNumber, vector<int>&path){
        if(k == 0)
        {
            if(n == 0) answers.push_back(path);
            return;
        }
        
        if(n < 0 || usedNumber > 9) return;
        
        path.push_back(usedNumber);
        fun(k-1, n - usedNumber, usedNumber + 1, path);
        path.pop_back();
        fun(k, n, usedNumber + 1, path);
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>path;
        fun(k, n, 1, path);
        return answers;
    }
};
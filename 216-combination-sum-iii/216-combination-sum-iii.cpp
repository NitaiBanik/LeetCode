class Solution {
public:
    vector<int>numbers;    
    vector<vector<int>> answers;
    
    void fun(int k, int n, int usedNumber){
        if(k == 0)
        {
            if(n == 0) answers.push_back(numbers);
            return;
        }
        
        if(n < 0 || usedNumber > 9) return;
        
        numbers.push_back(usedNumber);
        fun(k-1, n - usedNumber, usedNumber + 1);
        numbers.pop_back();
        fun(k, n, usedNumber + 1);
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        fun(k, n, 1);
        return answers;
    }
};
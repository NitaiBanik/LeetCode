class Solution {
public:
    vector<int>numbers;
    
    vector<vector<int>> answers;
    
    void fun(int pos, int k, int n, int usedNumber){
        if(n < 0) return;
        if(pos == k)
        {
            if(n == 0) answers.push_back(numbers);
            return;
        }
        
        for(int i = usedNumber; i <= 9; i++){
            numbers.push_back(i);
            fun(pos + 1, k, n - i, i + 1);
            numbers.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        fun(0, k, n, 1);
        return answers;
    }
};
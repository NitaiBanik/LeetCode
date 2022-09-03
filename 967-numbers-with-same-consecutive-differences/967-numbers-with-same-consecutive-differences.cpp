class Solution {
public:
    void fun(int pos, int prev, int diff, int num, vector<int>& answer){
        if(pos == 0){
            answer.push_back(num);
            return;
        }
        
        for(int i = 0; i<= 9; i++){
            if(abs(prev-i) == diff){
                fun(pos-1, i, diff, num * 10 + i, answer);
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> answer;
        for(int i = 1; i<= 9; i++){
            fun(n - 1, i, k, i, answer);
        }
        
        return answer;
    }
};
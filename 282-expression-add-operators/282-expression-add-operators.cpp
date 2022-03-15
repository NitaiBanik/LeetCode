class Solution {
public:
    int toInt(char ch){ return ch-'0'; }
    
    void solve(int pos, long total, long previousValue, long currentNum, int& target, string& num, string expression, vector<string>& expressions){
        
        if(pos == num.size()){
            //cout<<expression<<endl;
            if(total == target && currentNum == 0) expressions.push_back(expression);
            return;
        }
        
        long currentValue = currentNum * 10 + toInt(num[pos]);
        string currentString = to_string(currentValue);
        if(currentValue > 0){
            solve(pos + 1, total, previousValue, currentValue, target, num, expression, expressions);
        }
        
        if(expression == ""){
            solve(pos + 1, total+currentValue, currentValue, 0, target, num, expression+currentString, expressions);
        }
        else{ 
            solve(pos + 1, total + currentValue, currentValue, 0, target, num, expression+'+'+currentString, expressions);
            solve(pos + 1, total - currentValue, -currentValue,0, target, num, expression+'-'+currentString , expressions);
            solve(pos + 1, total - previousValue + previousValue * currentValue, previousValue*currentValue,0, target, num, expression+'*'+currentString , expressions);
        }   
        
    }
    
    vector<string> addOperators(string num, int target) {
        
        vector<string> expressions;
        
        solve(0, 0, 0, 0, target, num, "", expressions);
        
        return expressions;
    }
};
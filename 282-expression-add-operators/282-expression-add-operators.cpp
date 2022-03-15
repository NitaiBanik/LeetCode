class Solution {
public:
    
    void solve(int pos, long total, long previousValue, long currentNum, string currentString, int& target, string& num, string expression, vector<string>& expressions){
        
        if(pos == num.size()){
            //cout<<expression<<endl;
            if(total == target && currentNum == 0) expressions.push_back(expression);
            return;
        }
        
        long currentValue = currentNum * 10 + (num[pos] - '0');
        if(currentValue > 0){
            solve(pos + 1, total, previousValue, currentValue,currentString+num[pos], target, num, expression, expressions);
        }
        
        if(expression == ""){
            solve(pos + 1, total+currentValue, currentValue, 0, "", target, num, expression+currentString + num[pos], expressions);
        }
        else{ 
            solve(pos + 1, total + currentValue, currentValue, 0, "", target, num, expression+'+'+currentString + num[pos], expressions);
            solve(pos + 1, total - currentValue, -currentValue,0, "", target, num, expression+'-'+currentString + num[pos] , expressions);
            solve(pos + 1, total - previousValue + previousValue * currentValue, previousValue*currentValue,0, "",target, num, expression+'*'+currentString + num[pos] , expressions);
        }   
        
    }
    
    vector<string> addOperators(string num, int target) {
        
        vector<string> expressions;
        
        solve(0, 0, 0, 0, "", target, num, "", expressions);
        
        return expressions;
    }
};
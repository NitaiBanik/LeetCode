class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        
        for(auto token: tokens){
            if(token.size() > 1 || token[0] >= '0' && token[0] <= '9')
                nums.push(stoi(token));
            else{
                int second = nums.top();
                nums.pop();
                int first = nums.top();
                nums.pop();
                
                if(token == "+")
                    nums.push(first + second);
                
                if(token == "-")
                    nums.push(first - second);
                
                if(token == "*")
                    nums.push(first * second);
                
                if(token == "/")
                    nums.push(first / second);
            }
        }
        
        return nums.top();
        
    }
};
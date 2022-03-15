class Solution {
public:
    bool isAlpha(char ch){
        return ch >= 'a' && ch <= 'z';
    }
    string minRemoveToMakeValid(string s) {
        
        stack<int> indexes;
        
        for(int i = 0 ; i < s.size(); i++){
            if(!isAlpha(s[i])){
                if(s[i] == '(') indexes.push(i);
                
                else if(!indexes.empty() && s[indexes.top()] == '('){
                    indexes.pop();
                }
                else s[i] = '!';
            }
        }
       while(!indexes.empty()){
           s[indexes.top()] = '!';
           indexes.pop();
       }
        string ans = "";
        for(int i = 0; i < s.size(); i++)
            if(s[i] != '!') ans+=s[i];
        return ans;
    }
};
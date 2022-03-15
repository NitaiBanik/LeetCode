class Solution {
public:
    bool isAlpha(char ch){
        return ch >= 'a' && ch <= 'z';
    }
    string minRemoveToMakeValid(string s) {
        vector<bool>isValidIndex(s.size(), false);
        
        stack<int> indexes;
        
        for(int i = 0 ; i < s.size(); i++){
            if(isAlpha(s[i])) isValidIndex[i] = true;
            else{
                if(s[i] == '(') indexes.push(i);
                
                else if(!indexes.empty() && s[indexes.top()] == '('){
                    isValidIndex[i] = true;
                    isValidIndex[indexes.top()] = true;
                    indexes.pop();
                }
            }
        }
        string ans ="";
        for(int i = 0; i < s.size(); i++)
            if(isValidIndex[i]) ans+=s[i];
        return ans;
    }
};
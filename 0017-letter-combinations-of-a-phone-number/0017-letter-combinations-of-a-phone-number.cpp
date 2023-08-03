class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        
        map<char, string> chars;
        chars['2'] = "abc";
        chars['3'] = "def";
        chars['4'] = "ghi";
        chars['5'] = "jkl";
        chars['6'] = "mno";
        chars['7'] = "pqrs";
        chars['8'] = "tuv";
        chars['9'] = "wxyz";
        
        vector<string> ans, tmp;
        
        for(int i = 0; i < chars[digits[0]].size(); i++){
            string tmpp = "";
            tmpp += chars[digits[0]][i];
            ans.push_back(tmpp);
        }
        
        for(int i = 1; i < digits.size(); i++){
            for(int j = 0; j < chars[digits[i]].size(); j++){
                for(int k = 0; k< ans.size(); k++)
                    tmp.push_back(ans[k] + chars[digits[i]][j]);
            }  
            ans = tmp;
            tmp.clear();
        }
        return ans;
    }
};
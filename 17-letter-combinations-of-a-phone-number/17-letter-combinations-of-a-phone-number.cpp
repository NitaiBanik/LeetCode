class Solution {
public:
    vector<string> answers;
    map<char, string> mp;
    
    string str = "";
    void recursion(string digits, int pos){
        if(pos == digits.size())
        {
            answers.push_back(str);
            return;
        }
        for(int j = 0; j < mp[digits[pos]].size(); j++){
            str +=  mp[digits[pos]][j];
            recursion(digits, pos + 1);
            str.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return answers;
        
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        
        recursion(digits, 0);
        return answers;
    }
};
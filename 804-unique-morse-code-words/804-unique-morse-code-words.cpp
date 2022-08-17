class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> codes = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        map<string, bool> morseCodes;
        
        for(auto word: words){
            string temp = "";
            for(auto ch: word)
                temp += codes[ch  - 'a'];
            
            morseCodes[temp] = true;
        }
        
        return morseCodes.size();
        
    }
};
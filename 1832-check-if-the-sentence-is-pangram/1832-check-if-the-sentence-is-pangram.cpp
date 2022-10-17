class Solution {
public:
    bool checkIfPangram(string chars) {
        unordered_set<char> sett;
        
        for(auto ch: chars)
            sett.insert(ch);
        
        return sett.size() == 26;
    }
};
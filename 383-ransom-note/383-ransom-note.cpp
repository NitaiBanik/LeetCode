class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(magazine.size() < ransomNote.size()) return false;
        
        vector<int> frequency(26, 0);
        for(auto chr: magazine)
            frequency[chr-'a']++;
        for(auto chr: ransomNote){
            if(--frequency[chr-'a'] < 0) return false;
        }
        return true;
    }
};
class Solution {
public:
    bool isFound(string s, vector<vector<int>>& characterIndecies){
        int foundAt = -1; 
        for(int i = 0; i < s.size(); i++){
            auto position = lower_bound(characterIndecies[s[i]-'a'].begin(), characterIndecies[s[i]-'a'].end(), foundAt);    

            if(position == characterIndecies[s[i]-'a'].end())
                return false;

            foundAt = *position + 1;
        }
        return true;
    }
    
    int numMatchingSubseq(string s, vector<string>& words) {
        
        vector<vector<int>> characterIndecies(26);  
        for(int i = 0; i < s.size(); i++)
            characterIndecies[s[i]-'a'].push_back(i);
        
        int count = 0;
        for(auto word: words){
            count += isFound(word, characterIndecies);
        }
        
        return count;
    }
};
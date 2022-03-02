class Solution {
public:
     map<char, vector<int>> createCharacterIndicies(string t){
        map<char, vector<int>> characterIndecies;
         
        for(int i = 0; i < t.size(); i++)
            characterIndecies[t[i]].push_back(i);
         
         return characterIndecies;
    }
    
    bool isFound(string s, string t,  map<char, vector<int>> characterIndecies){
        int foundAt = -1; 
        for(int i = 0; i < s.size(); i++){

            if(characterIndecies.find(s[i]) == characterIndecies.end())
                return false;

            vector<int> indicies = characterIndecies[s[i]];

            foundAt = lower_bound(indicies.begin(), indicies.end(), foundAt) - indicies.begin();    

            if((foundAt == indicies.size()) || (t[indicies[foundAt]] != s[i]))
                return false;

            foundAt = indicies[foundAt] + 1;
        }
        return true;
    }
    
    bool isSubsequence(string s, string t) {    
        auto characterIndecies = createCharacterIndicies(t);
    
        return isFound(s, t, characterIndecies);
        
    }
};
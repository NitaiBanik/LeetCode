class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        map<char, vector<int>> characterIndecies;
        
        for(int i = 0; i < t.size(); i++)
            characterIndecies[t[i]].push_back(i);
        
    /*    for(auto s: characterIndecies){
            char ch = s.first;
            vector<int> vec = s.second;
            cout<<ch<<" positions: ";
            for(auto id: vec) cout<<id<<" ";
            cout<<endl;
        }
            */
        
        int foundAt = -1; 

        for(int i = 0; i < s.size(); i++){

            if(characterIndecies.find(s[i]) == characterIndecies.end()){
                cout<<" first Not Found: "<<s[i]<<endl;
                return false;
            }

            vector<int> indicies = characterIndecies[s[i]];
            cout<<"khujbo = "<<s[i]<<" Index Er pore = "<<foundAt<<endl;
            
            for(auto id: indicies)
                cout<<id<<" ";
            cout<<endl;

            foundAt = lower_bound(indicies.begin(), indicies.end(), foundAt) - indicies.begin();
            
            cout<<"FoundAt "<<foundAt<<endl;

            if((foundAt == indicies.size()) || (t[indicies[foundAt]] != s[i])){
                cout<<"next Not Found: "<<s[i]<<endl;
                return false;
            }

            foundAt = indicies[foundAt] + 1;
        }
        return true;
    }
};
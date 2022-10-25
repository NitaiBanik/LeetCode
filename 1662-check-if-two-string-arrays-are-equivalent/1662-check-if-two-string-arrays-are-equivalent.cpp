class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
       string vec1 = "", vec2= "";
        for(auto val : word1){
            for(auto chr: val) vec1 += chr;
        }
        
         for(auto val : word2){
            for(auto chr: val) vec2 += chr;
        }
        
        return vec1 == vec2;
        
    }
};
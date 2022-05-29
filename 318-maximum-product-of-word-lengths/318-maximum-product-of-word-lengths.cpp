class Solution {
public:
    int getExistingLetterAsBits(string word){
        int value = 0;
        for(int i = 0; i < word.size(); i++)
            value|= (1 << (word[i]-'a'));
        
        return value;
    }
    
    int maxProduct(vector<string>& words) {
        
        int mx = 0;
        
        for(int i = 0; i < words.size(); i++){
            int existingLetters = getExistingLetterAsBits(words[i]);
            //cout<<words[i]<<" existingLetters = "<<existingLetters<<endl;
            for(int j =  i + 1; j < words.size(); j++){
                int existingLetters2 = getExistingLetterAsBits(words[j]);
               // cout<<words[j]<<" existingLetters2 = "<<existingLetters2<<endl;
                
                if(existingLetters & existingLetters2) continue;
        
                mx = max(mx, (int)words[i].size() * (int)words[j].size());
            }
        }
        
        return mx;
        
    }
};
class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        
        int mx = 0;
        
        for(auto sentence: sentences){
            
            int space = 0;
            
            for(auto chr: sentence){
                if(chr ==' ') space++;
            }
            
            mx = max(mx, space + 1);
        }
        return mx;
    }
};
class Solution {
public:
    bool isSameFrequency( vector<int>& freq2,  vector<int>& freq1, char ch){
        return freq2[ch] == freq1[ch];
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> freq1(126, 0);
        vector<int> freq2(126, 0);
        int numberOfDistinctCharInP = 0;
        int numberOfDistinctCharInS = 0;
        
        for(int i = 0; i < p.size(); i++)
        {
            if(freq1[p[i]] == 0) numberOfDistinctCharInP++;
            freq1[p[i]]++;
        }
        
        int lf = 0;
        vector<int>positions;
        
        for(int i = 0; i < s.size() && lf < s.size(); i++){
            freq2[s[i]]++;
            
            if(isSameFrequency(freq2,freq1, s[i]))
                numberOfDistinctCharInS++;
            
            if(freq2[s[i]] > freq1[s[i]]){
                while(lf < s.size() && lf <= i && freq2[s[i]] > freq1[s[i]]){
                     if(freq2[s[lf]] == freq1[s[lf]]) numberOfDistinctCharInS--;
                    freq2[s[lf++]]--;
                    
                }
            }
            if(numberOfDistinctCharInS == numberOfDistinctCharInP){
                positions.push_back(lf);
            }
        }
        return positions;
    }
};
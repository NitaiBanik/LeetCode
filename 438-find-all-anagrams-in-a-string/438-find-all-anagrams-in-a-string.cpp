class Solution {
public:
    bool isSameFrequency(vector<int>& freq1, vector<int>& freq2, char ch){
        return freq2[ch] == freq1[ch];
    }
    
    int calculateFrequencyInP(vector<int>& freq1, string& p){
        int numberOfDistinctCharInP = 0;
        for(auto chr: p)
        {
            if(freq1[chr] == 0)
                numberOfDistinctCharInP++;
            freq1[chr]++;
        } 
        return numberOfDistinctCharInP;
    }
    
    void calculate(vector<int>& freq1, vector<int>& freq2, string& s, int numberOfDistinctCharInP, vector<int>& positions){
        int lf = 0, numberOfDistinctCharInS = 0;
        for(int i = 0; i < s.size() && lf < s.size(); i++){
            freq2[s[i]]++;
            
            if(isSameFrequency(freq1, freq2, s[i]))
                numberOfDistinctCharInS++;

            while(lf < s.size() && lf <= i && freq2[s[i]] > freq1[s[i]]){
                 if(freq2[s[lf]] == freq1[s[lf]]) numberOfDistinctCharInS--;
                freq2[s[lf++]]--;

            }
            if(numberOfDistinctCharInS == numberOfDistinctCharInP){
                positions.push_back(lf);
            }
        }
        
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> freq1(126, 0);
        vector<int> freq2(126, 0);
        int numberOfDistinctCharInP = 0;
        
        numberOfDistinctCharInP = calculateFrequencyInP(freq1, p);

        vector<int>positions;     
        calculate(freq1, freq2, s, numberOfDistinctCharInP, positions);
        
        return positions;
    }
};
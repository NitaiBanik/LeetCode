class Solution {
public:
     bool isSameFrequency(vector<int>& freq1, vector<int>& freq2, char ch){
        return freq2[ch] == freq1[ch];
    }
    
    int calculateFrequencyInS1(vector<int>& freq1, string& s1){
        int numberOfDistinctCharInS1 = 0;
        for(auto chr: s1)
        {
            if(freq1[chr] == 0)
                numberOfDistinctCharInS1++;
            freq1[chr]++;
        } 
        return numberOfDistinctCharInS1;
    }
    
    bool calculate(vector<int>& freq1, vector<int>& freq2, string& s, int numberOfDistinctCharInP){
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
                return true;
            }
        }
        return false;
    }
    bool checkInclusion(string s1, string s2) {
        vector<int> freq1(126, 0);
        vector<int> freq2(126, 0);
        int numberOfDistinctCharInS1 = 0;
        
        numberOfDistinctCharInS1 = calculateFrequencyInS1(freq1, s1);    
        return calculate(freq1, freq2, s2, numberOfDistinctCharInS1);
    }
};
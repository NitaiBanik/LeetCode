class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        vector<int>freq(2005), occur(1001, 0);
        
        bool isOk = true;
        
        for(auto num: arr){
            freq[num + 1000]++;
        }
        
        for(int i = 0; i < 2000; i++){
            if(freq[i] > 0){
                occur[freq[i]]++;
                if(occur[freq[i]] > 1) isOk = false;
            }
        }
        
        return isOk;
    }
};
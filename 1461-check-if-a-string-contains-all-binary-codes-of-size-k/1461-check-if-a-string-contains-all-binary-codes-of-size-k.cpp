class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int total = 1 << k;
        int allBitsOne = total - 1;
        
        int hash = 0;
        
        vector<bool> found(total, false);        
        for(int i = 0; i < s.size(); i++){
            hash = ((hash << 1) & allBitsOne) | (s[i] == '1');
            if(i >= k - 1 && found[hash] == false){
                found[hash] = true;
                total--;
                if(!total) return true;
            }
        }
        return false;
    }
};
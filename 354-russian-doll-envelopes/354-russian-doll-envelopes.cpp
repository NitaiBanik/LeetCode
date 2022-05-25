class Solution {
public:
    static bool comp(vector<int>& first, vector<int>& second){
        if(first[0] == second[0]) return first[1] > second[1];
        return first[0] < second[0];
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), comp);
        
        vector<int>lis;
        
        
        for(int i = 0; i < envelopes.size(); i++){
            int height = envelopes[i][1];
            
            int index = lower_bound(lis.begin(), lis.end(), height) - lis.begin();
            
            if(index >= lis.size())
                lis.push_back(height);
            else lis[index] = height;
        }
        
        return lis.size();
    }
};
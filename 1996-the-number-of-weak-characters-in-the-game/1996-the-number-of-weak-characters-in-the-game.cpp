class Solution {
public:
    static bool comp(vector<int>& v1, vector<int>& v2){
        if(v1[0] == v2[0])
            return v1[1] > v2[1];
        
        return v1[0] < v2[0];
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), comp);
        
        int cnt = 0, mx = INT_MIN;
        for(int i = properties.size() - 1; i>= 0; i--){
            if(properties[i][1] < mx) cnt++;
            
            mx = max(mx, properties[i][1]);
        }
        
        return cnt;
    }
};
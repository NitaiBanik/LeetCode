class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        
        int prev = 0, ans = 0;
        
        for(auto dis: rungs){
            int d = (dis - prev);     
            d = (d / dist) + (d % dist > 0);    
            ans +=(d - 1);
            
            prev = dis;
        }
        return ans;
    }
};
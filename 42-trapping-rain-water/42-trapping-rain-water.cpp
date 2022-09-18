class Solution {
public:
    int trap(vector<int>& height) {
        int totalSum = 0;
        int ln = height.size();
        if(ln == 0) return 0;
        vector<int>leftMax(ln + 1);
        
        int mx = height[0];
        
        for(int i = 0; i< ln; i++){ 
            leftMax[i] = mx; 
            mx = max(mx, height[i]);
           }
        
         mx = height[ln-1];        
         for(int i = ln-1; i >= 0; i--){ 
              int mn = min(leftMax[i], mx);
            if(height[i]<mn) totalSum+=(mn- height[i]);
            mx = max(mx, height[i]);
           }
        
        return totalSum;     
    }
};
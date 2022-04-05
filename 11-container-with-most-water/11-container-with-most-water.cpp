class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int lf = 0, rt = height.size() - 1;
        int mx = 0;
         while(lf < rt){
             
             if(height[lf] < height[rt]){
                 mx= max(mx, height[lf] * (rt - lf));
                 lf++;
             }
             else{
                 mx= max(mx, height[rt] * (rt - lf));
                 rt--;
             }
         }
        return mx;
    }
};
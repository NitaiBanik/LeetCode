class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int max_h = 0, max_v = 0;
        
        max_h = max(horizontalCuts[0], h - horizontalCuts[horizontalCuts.size() - 1]);
        max_v = max(verticalCuts[0], w - verticalCuts[verticalCuts.size() - 1]);
        
        for(int i = 1; i < horizontalCuts.size(); i++)
            max_h = max(max_h, horizontalCuts[i] - horizontalCuts[i-1]);
        
         for(int i = 1; i < verticalCuts.size(); i++)
            max_v = max(max_v, verticalCuts[i] - verticalCuts[i-1]);
        
        return ((long long)max_h * (long long)max_v) % 1000000007;
        
    }
};
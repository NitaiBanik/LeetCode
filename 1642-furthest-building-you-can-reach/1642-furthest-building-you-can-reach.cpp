class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int>bricksUsed;
        int i = 0;
        
        for(i = 0; i < heights.size() - 1; i++){
            if(heights[i] >= heights[i + 1])
                continue;
            int dif = heights[i + 1] - heights[i];
            
            if(bricks >= dif){
                bricks -= dif;
                bricksUsed.push(dif);
            }
            else if(ladders > 0){
                ladders--;
                if(!bricksUsed.empty() && bricksUsed.top() >= dif){
                    bricks += (bricksUsed.top() - dif);
                    bricksUsed.pop();
                    bricksUsed.push(dif);
                }
            }
            else break;
        }
        return i;
    }
};
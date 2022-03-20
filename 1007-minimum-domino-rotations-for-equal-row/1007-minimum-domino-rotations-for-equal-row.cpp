class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        
        int up = tops[0];
        int down = bottoms[0];
        int x = 0, y = 0;
        
        for(int i = 0; i < tops.size(); i++){
            if(tops[i] == up || bottoms[i] == up) x++;
            if(tops[i] == down || bottoms[i] == down) y++;
        }
        
        if(x != tops.size() && y != bottoms.size()) return -1;
        x = 0, y = 0;
        
        for(int i = 0; i < tops.size(); i++){
            if(tops[i] != up) x++;
             if(bottoms[i] != down) y++;
        }
        
        int mn = 999999;
        
        mn =  min(x,y);
        
        x = 0, y = 0;
        
        for(int i = 0; i < tops.size(); i++){
            if(bottoms[i] != up) x++;
             if(tops[i] != down) y++;
        }
        
         mn =  min(mn, min(x,y));
        
        return mn;
    }
};
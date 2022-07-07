class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int>vec(queries.size(), 0);
        for(int i = 0; i < queries.size(); i++){
            int cnt = 0;
        for(int j = 0; j < points.size(); j++){
                long long disX = (queries[i][0] - points[j][0]);
                disX *= disX;
                
                long long disY = (queries[i][1] - points[j][1]);
                disY *= disY;
                
                double diss = (double)sqrt((disX + disY));
                
                if(diss <= (double)queries[i][2])
                    cnt++;
            
            vec[i]= cnt;
            }
        }
        
        return vec;
    }
};
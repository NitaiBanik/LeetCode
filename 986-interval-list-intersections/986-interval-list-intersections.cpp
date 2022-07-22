class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> answer;
        int i = 0, j = 0;
        
        int firstListSize = firstList.size();
        int secondListSize = secondList.size();
        
        while(i < firstListSize && j < secondListSize){
            
            int mn = max(secondList[j][0], firstList[i][0]);
            int mx = min(secondList[j][1], firstList[i][1]);
            
            if(mn <= mx)
                answer.push_back({mn, mx});
            
            if(secondList[j][1] > firstList[i][1])
                i++;
            else j++;
        }
        
        return answer;
    }
};
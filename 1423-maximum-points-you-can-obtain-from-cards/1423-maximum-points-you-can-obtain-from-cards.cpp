class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        if(cardPoints.size() < k) return 0;
        
        cardPoints.push_back(0);
        
        for(int i = cardPoints.size() - 1; i >= 1; i--){
            cardPoints[i] = cardPoints[i - 1];
        }
        cardPoints[0] = 0;
        for(int i = 1; i< cardPoints.size(); i++){
            cardPoints[i] += cardPoints[i -1];
        }
        
        int mx = 0;
        for(int i = 0; i <= k; i++){
            int fromFirst = i;
            int fromLast = k - i;
            
            int sum = cardPoints[fromFirst];
            int sum2 = cardPoints[cardPoints.size() - 1] - cardPoints[cardPoints.size() - fromLast - 1];
            
            mx = max(mx, sum + sum2);
        }
        
        return mx;
    }
};
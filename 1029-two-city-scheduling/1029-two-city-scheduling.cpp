class comp{
    public:
    bool operator()(pair<int, int>& a, pair<int, int>&b){
       return a.first > b.first;
   }
};
class Solution {
public:
   
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
      priority_queue<pair<int,int>, vector<pair<int,int>>, comp>pq;
      int n = costs.size(), sum = 0;
        
        for(int i = 0; i < n; i++){
            pq.push({(costs[i][0] - costs[i][1]),i});
        }
        
        n /= 2;
        while(!pq.empty()){
            if(!n){
                sum += costs[pq.top().second][1];
            }
            else{
                  sum += costs[pq.top().second][0];
                n--;
            }
            pq.pop();
        }
        
        return sum;
    }
};
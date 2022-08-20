class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int cnt = 0;
        for(int i = 0; i < stations.size(); i++){
            if(stations[i][0] > startFuel){
                while(!pq.empty() && stations[i][0] > startFuel){
                    startFuel += pq.top();
                    pq.pop();
                    cnt++;
                }
            }
            if(stations[i][0] > startFuel) return -1;

            pq.push(stations[i][1]);
        }
        
       while(!pq.empty() && target > startFuel){
           startFuel += pq.top();
           pq.pop();
           cnt++;
       }
        
        return startFuel >= target ? cnt: -1;
    }
};
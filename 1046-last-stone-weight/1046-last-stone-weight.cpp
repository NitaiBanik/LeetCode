class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(auto val: stones){
            pq.push(val);
        }
        
        int ans;
        while(!pq.empty()){
            if(pq.size() == 1) {
                ans = pq.top();
                break;
            }
            else{
                int f = pq.top();
                pq.pop();
                int s = pq.top();
                pq.pop();
                
                pq.push(f- s);
            }
        }
        return ans;
    }
};
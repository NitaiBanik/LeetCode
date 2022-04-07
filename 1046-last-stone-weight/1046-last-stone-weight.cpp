class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(auto val: stones){
            pq.push(val);
        }
        
        while(pq.size() > 1){
            int f = pq.top();
            pq.pop();
            int s = pq.top();
            pq.pop();

            if(f - s > 0)
            pq.push(f- s);
        }
        return pq.size() == 0 
            ? 0
            : pq.top();
    }
};
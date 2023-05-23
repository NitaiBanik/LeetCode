class KthLargest {
public:
    priority_queue<int>pq;
    int kk;
    KthLargest(int k, vector<int>& nums) {
     kk = k;
        for(int i = 0; i < nums.size(); i++)
        {
            pq.push(-nums[i]);
            if(pq.size()>k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(-val);
            if(pq.size()>kk) pq.pop();
        return -pq.top();
    }
};
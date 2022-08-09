class MedianFinder {
public:
    priority_queue<int>maxHeap;
    priority_queue<int, vector<int>, greater<int>>minHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(!minHeap.empty() && minHeap.top() < num) minHeap.push(num);
        else maxHeap.push(num);
        
       if((minHeap.size() + 1) < maxHeap.size()){
           minHeap.push(maxHeap.top());
           maxHeap.pop();
       }
       if((maxHeap.size() + 1) < minHeap.size()){
           maxHeap.push(minHeap.top());
           minHeap.pop();
       }
    }
    
    double findMedian() {
        if(maxHeap.size() == minHeap.size()) 
            return maxHeap.empty() ? 0 : (double)(maxHeap.top() + minHeap.top()) / 2.0;
      return maxHeap.size() > minHeap.size()? maxHeap.top(): minHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
class MyStack {
public:
    queue<int> mainQueue;
    
    MyStack() {
        
    }
    
    void push(int x) {
        
        mainQueue.push(x);
        
        int queueSize = mainQueue.size();
        
         while(queueSize > 1){
            mainQueue.push(mainQueue.front());
            mainQueue.pop();
            queueSize--;
        }   
    }
    
    int pop() {
        int top = mainQueue.front();
        mainQueue.pop();
        return top;
    }
    
    int top() {
        return mainQueue.front();
    }
    
    bool empty() {
        return mainQueue.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
class MyStack {
public:
    queue<int> temporaryQueue, mainQueue;
    
    MyStack() {
        
    }
    
    void push(int x) {
       temporaryQueue = mainQueue;
        
        while(!mainQueue.empty()){
            mainQueue.pop();
        }
        
        mainQueue.push(x);
        
         while(!temporaryQueue.empty()){
            mainQueue.push(temporaryQueue.front());
            temporaryQueue.pop();
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
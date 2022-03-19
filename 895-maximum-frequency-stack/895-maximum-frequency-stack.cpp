class FreqStack {
public:
    int maxFrequency;
    map<int, int>frequency;
    map<int, stack<int>> frequency_stack;
    FreqStack() {
       maxFrequency = 0;
       frequency.clear();
       frequency_stack.clear();
    }
    
    void push(int val) {
        frequency[val]++;
        
        int currentFrequency = frequency[val];
        maxFrequency = max(maxFrequency, currentFrequency);
        frequency_stack[currentFrequency].push(val);
    }
    
    int pop() {
        
        int ans = frequency_stack[maxFrequency].top();
        frequency_stack[maxFrequency].pop();
        frequency[ans]--;
        if(frequency_stack[maxFrequency].empty())
            maxFrequency--;
        
        return ans; 
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
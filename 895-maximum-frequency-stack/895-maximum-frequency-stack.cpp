class FreqStack {
public:
    int maxFrequency;
    unordered_map<int, int>frequency;
    vector<vector<int>> frequency_stack;
    FreqStack() {
       maxFrequency = 0;
       frequency.clear();
       vector<vector<int>>dp(20002);
       frequency_stack =  dp;
    }
    
    void push(int val) {
        frequency[val]++;
        
        int currentFrequency = frequency[val];
        maxFrequency = max(maxFrequency, currentFrequency);
        frequency_stack[currentFrequency].push_back(val);
    }
    
    int pop() {
        
        int ans = frequency_stack[maxFrequency][frequency_stack[maxFrequency].size()-1];
        frequency_stack[maxFrequency].pop_back();
        frequency[ans]--;
        if(!frequency_stack[maxFrequency].size())
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
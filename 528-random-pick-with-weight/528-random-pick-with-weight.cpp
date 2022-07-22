class Solution {
public:
    vector<int> weightsSums;
    int totalSum=0;
    Solution(vector<int>& w) {
        weightsSums = w;
        for(int i = 1; i < w.size(); i++)
            weightsSums[i] = weightsSums[i-1] + w[i];     
        
        totalSum = weightsSums.back();
    }
    
    int pickIndex() {
        int index = rand() % totalSum;
        int id = lower_bound(weightsSums.begin(), weightsSums.end(), index + 1) - weightsSums.begin();
        return id;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
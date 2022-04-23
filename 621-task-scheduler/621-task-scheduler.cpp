class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>taskCount(26, 0);
        
        priority_queue<int>frequency;
        queue<pair<int, int>>collingFrequency;
        
        for(auto task: tasks)
            taskCount[task-'A']++;
        
        for(int i = 0; i < 26; i++)
            if(taskCount[i] > 0)
                frequency.push(taskCount[i]);
        
        int time = 0;
        while(!frequency.empty() || !collingFrequency.empty()){
            time++;
            
            if(!frequency.empty()){
                int top = frequency.top();
                frequency.pop();
                
                if(top > 1) collingFrequency.push({top-1, time + n});
            }
            
            if(!collingFrequency.empty() && collingFrequency.front().second == time){
                frequency.push(collingFrequency.front().first);
                collingFrequency.pop();
            }
        }
        return time;
    }
};
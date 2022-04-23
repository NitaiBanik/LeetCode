class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>taskCount(26, 0);
        
        int maxFrequency = 0, maxFrequencyCount = 0;
        
        for(auto task: tasks){
            taskCount[task-'A']++;
            
            if(taskCount[task-'A'] == maxFrequency)
                maxFrequencyCount++;
            
            if(taskCount[task-'A'] > maxFrequency){
                maxFrequency = taskCount[task-'A'];
                maxFrequencyCount = 1;
            }     
        }
        
        int totalPartition = maxFrequency - 1;
        int availableSlotsInAPartition = n - maxFrequencyCount + 1;
        int totalAvailableSlots = totalPartition * availableSlotsInAPartition;
        int availableTasks =  tasks.size() - maxFrequency *  maxFrequencyCount;
        
        int extraSlots = max(0, totalAvailableSlots - availableTasks);
        
        return tasks.size() + extraSlots;
    }
};
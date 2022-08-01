class Solution {
public:
    void topologicalSort(int node, vector<int> dependencies[],  vector<int>& indegree,  vector<int>& visited, bool& hasCycle, int& numCourses){
        visited[node] = 1;
        numCourses--;
        
        for(auto nodes: dependencies[node]){
            indegree[nodes]--;
            if(indegree[nodes] == 0)
                topologicalSort(nodes, dependencies, indegree, visited, hasCycle, numCourses);
            
            
            if(visited[nodes] == 1){
                hasCycle = true;
                return;
            }
        }
        
        visited[node] = 2;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> dependencies[numCourses];
        vector<int> indegree(numCourses, 0), visited(numCourses, 0);
        
        for(auto prerequisite: prerequisites){
            indegree[prerequisite[0]]++;
            dependencies[prerequisite[1]].push_back(prerequisite[0]);
        }

        bool hasCycle = false;
        int numOfCourses = numCourses;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0 && visited[i] == 0){
                topologicalSort(i, dependencies, indegree, visited, hasCycle, numOfCourses);
                if(hasCycle) return 0;
            }
        }
        
        return numOfCourses == 0;
        
    }
};
class Solution {
public:
    void topologicalSort(int node, vector<int> dependencies[],  vector<int>& indegree,  vector<int>& visited, vector<int>& answer, bool& hasCycle){
        visited[node] = 1;
        answer.push_back(node);
        
        for(auto nodes: dependencies[node]){
            indegree[nodes]--;
            if(indegree[nodes] == 0)
                topologicalSort(nodes, dependencies, indegree, visited, answer, hasCycle);
            
            
            if(visited[nodes] == 1){
                cout<<nodes<<endl;
                hasCycle = true;
                return;
            }
        }
        
        visited[node] = 2;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
       vector<int> dependencies[numCourses];
       vector<int> indegree(numCourses, 0), visited(numCourses, 0);
        
        for(auto prerequisite: prerequisites){
            indegree[prerequisite[0]]++;
            dependencies[prerequisite[1]].push_back(prerequisite[0]);
        }
        
        vector<int> answer;
        bool hasCycle = false;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0 && visited[i] == 0){
                topologicalSort(i, dependencies, indegree, visited, answer, hasCycle);
                if(hasCycle) return {};
            }
        }
        if(answer.size() == numCourses)
            return answer;
        return {};
    }
};
class Solution {
public:
    vector<int>edges[100001];
    bool visited[100001];
    
    vector<int> positions;
    vector<char>chars;
    
    void dfs(string &s, int node){
        visited[node] = true;
        
        positions.push_back(node);
        chars.push_back(s[node]);
        
        for(auto n: edges[node])
            if(!visited[n]){
                dfs(s, n);
            }
    }
        
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        for(auto edge: pairs){
            edges[edge[0]].push_back(edge[1]);
            edges[edge[1]].push_back(edge[0]);
        }
        
        for(int i = 0; i < s.size(); i++){
            if(!visited[i]){
                dfs(s, i);
                
                sort(positions.begin(), positions.end());
                sort(chars.begin(), chars.end());
                
                for(int idx = 0; idx < chars.size(); idx++)
                    s[positions[idx]] = chars[idx];
                
                positions.clear();
                chars.clear();
            }
        }
        
        return s;
    }
};
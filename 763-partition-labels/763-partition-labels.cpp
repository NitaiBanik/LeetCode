class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        vector<int> maxPosition(125, -1);
        
        for(int i = 0; i < s.size(); i++)
            maxPosition[s[i]] = max(maxPosition[s[i]], i);
            
            int cnt = 0;
            
            vector<int> lengths;
           
            int currentMaxPosition = -1;
            
            for(int i = 0; i < s.size(); i++){
                cnt++;
                currentMaxPosition = max(currentMaxPosition, maxPosition[s[i]]);
                
                if(i == currentMaxPosition){
                    lengths.push_back(cnt);
                    cnt=0;
                    currentMaxPosition = -1;
                }
            }
        
        return lengths;
    }
};
class Solution {
public:
    int minOperations(vector<string>& logs) {
        
        int cnt = 0;
        
        for(auto log: logs){
            if(log == "../"){
                if(cnt) cnt--;
            }
            else if(log != "./")
                cnt++;
        }
        return cnt;
    }
};
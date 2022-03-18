class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<bool> vis(126,false);
        vector<int> freq(126,0);
        
        for(auto chr: s) freq[chr]++;
        
        string ans = "";
        
        for(auto chr: s){
            freq[chr]--;
            
            if(!vis[chr]){
                while(ans.size() > 0 && ans.back() > chr && freq[ans.back()] > 0){
                    vis[ans.back()] = false;
                    ans.pop_back();
                }
                ans += chr;
                vis[chr] = true;
            }
        }
        
        return ans;
        
    }
};
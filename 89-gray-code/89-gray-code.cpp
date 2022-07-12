class Solution {
public:
    vector<int> grayCode(int n) {
       vector<int>ans(1, 0);
        
        for(int i = 0; i < n; i++){
            int sz = ans.size();
            
            while(sz){
                ans.push_back(ans[sz-1] | (1 << i));
                sz--;
            }
        }
          return ans;
    }
};
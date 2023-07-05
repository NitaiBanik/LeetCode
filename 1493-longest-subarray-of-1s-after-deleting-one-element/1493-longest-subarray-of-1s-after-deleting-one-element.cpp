class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> vec;
        int cn = 0;
        for(auto n: nums){
            if(n == 1) cn++;
            else{
                vec.push_back(cn);
                if(cn != 0)     vec.push_back(0);
                cn = 0;
            }
        }
        
        if(cn > 0) vec.push_back(cn);
        
        if(vec.size() == 1) return vec[0] - 1 < 0 ? 0 :  vec[0] - 1;
        
        cn = 0;
       // for(auto x: vec) cout<<x<<endl;
          for(int i = 0; i < vec.size(); i++){
              if(vec[i] == 0){
                  int x = i > 0 ? vec[i-1] : 0;
                  int y = i < vec.size() - 1 ? vec[i + 1] : 0;
                  
                  cn = max(cn,  x  + y);
              }
          }
        
        return cn;
    }
};
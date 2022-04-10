class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        set<vector<int>> st;
        
        int range = (1 << nums.size());
        
        for(int val = 0; val < range; val++){
            vector<int> temp;
            for(int pos = 0; pos < nums.size(); pos++){
                if(val & (1 << pos)){
                    temp.push_back(nums[pos]);
                }
            }      
            st.insert(temp);
        }
        
        vector<vector<int>> ans;
        for(auto val: st)
            ans.push_back(val);
        
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>>vec;
    vector<int>tmp;
    
    void fun(vector<int>& inp, int pos){
        if(pos == inp.size()){
            vec.push_back(tmp);
            return;
        };
        
        tmp.push_back(inp[pos]);
        fun(inp, pos + 1);
        tmp.pop_back();
        fun(inp, pos + 1);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        fun(nums, 0);
        return vec;
    }
};
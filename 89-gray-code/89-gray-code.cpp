class Solution {
public:
    vector<int> fun(int pos){
        if(pos == 1) return {0, 1};
        
        vector<int> result;
        vector<int>temp = fun(pos-1);
        
        result = temp;
        
        for(int i = temp.size() - 1; i >=0; i--)
            result.push_back(temp[i] | (1 << (pos-1)));
        
        return result;
    }
    vector<int> grayCode(int n) {
          return fun(n);
    }
};
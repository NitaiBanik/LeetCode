class Solution {
public:
    string getSmallestString(int n, int k) {
        
        k-=n;
        
        vector<int>vec(n, 1);
        
        for(int i = n - 1; i >= 0; i--){
            vec[i] += min(k , 25);
            k -= min(k , 25);
            
            if(k ==0) break;
        }
        
        string s = "";
        
        for(int i = 0 ; i < n; i++)
            s += (char) vec[i] + 'a' - 1;
        
        return s;
    }
};
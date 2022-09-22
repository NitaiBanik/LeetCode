class Solution {
public:
    string reverseStr(string s, int k) {
        int lf = 0, rt = k;
        while(lf < s.size()){
            rt = min(rt, (int)s.size());
            
            for(int i = 0; i < (rt - lf)/ 2; i++)
                swap(s[lf + i], s[rt - i-1]);
            
            lf += (2 * k);
            rt += (2 * k);
        }
        return s;
    }
};
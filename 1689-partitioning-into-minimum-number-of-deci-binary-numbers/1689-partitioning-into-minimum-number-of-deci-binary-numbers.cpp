class Solution {
public:
    int minPartitions(string n) {
        int sum = 0, mx = 0;
        
        for(int i = n.size() - 1; i >= 0; i--){
            int value = n[i]-'0';

            mx = max(mx, value);
        }
        return  mx;
    }
};
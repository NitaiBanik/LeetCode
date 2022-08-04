class Solution {
public:
    int mirrorReflection(int p, int q) {
        
        int gcd = __gcd(p, q);
        int y = p / gcd;
        int x = q / gcd;
        
        if(x % 2 && y%2) return 1;
        else if(x%2 && y%2 == 0) return 2;
        else return 0;
        
    }
};
class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long m = n;
        return (m!= 0) && ((m & (m-1)) == 0);
    }
};
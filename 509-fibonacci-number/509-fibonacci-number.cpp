class Solution {
public:
    int fib(int n) {
        int first = 0, second = 1;
        int sum = 1;
        
        if(n == 0) return 0;
        if(n == 1) return 1;
         n--;
        while(n--){
            sum = first + second;
            first = second;
            second = sum;
        }
        
        return sum;
    }
};
class Solution {
public:
    int reverse(int x) {
        if(x == 0) return 0;

        int negativeLimit = 214748364;
        int positiveLimit = 214748364;
        
        if(x > 0){
            int reverseNumber = 0;
            while(x != 0){
                int reminder = x % 10;
                if(reverseNumber > positiveLimit) return 0;
                if(reverseNumber == positiveLimit && reminder > 7)  return 0;
                reverseNumber = reverseNumber * 10 + reminder;
                x/=10;
            }
            return reverseNumber;
        }
        else{
            if(x == -2147483648) return 0;
            x *= -1;
            int reverseNumber = 0;
            while(x != 0){
                int reminder = x % 10;
                x/=10;
                
                if(reverseNumber > negativeLimit) return 0;
                if(reverseNumber == negativeLimit && reminder > 8)  return 0;
                
                if(reverseNumber == negativeLimit && reminder < 9 && x == 0){
                    reverseNumber *= -1;
                    return reverseNumber * 10 - reminder;
                }
                
                reverseNumber = reverseNumber * 10 + reminder;
            }
            return -1 * reverseNumber;
        }
        return 0;
    }
};
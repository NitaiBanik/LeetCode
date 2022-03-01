class Solution {
public:
    int calculateForPositiveNumber(int x, int limit){   
        int reverseNumber = 0;
        
        while(x != 0){
            int reminder = x % 10;
            x/=10;

            if(reverseNumber > limit) return 0;       
            if(reverseNumber == limit && reminder > 7)  return 0;

            reverseNumber = reverseNumber * 10 + reminder;
        }
        
        return reverseNumber;
    }
    
    int calculateForNegativeNumber(int x, int limit){   
        
        if(x == -2147483648) return 0;

        x *= -1;
        int reverseNumber = 0;

        while(x != 0){
            int reminder = x % 10;
            x/=10;

            if(reverseNumber > limit) return 0;
            if(reverseNumber == limit && reminder > 8)  return 0;

            if(reverseNumber == limit && reminder < 9 && x == 0){
                reverseNumber *= -1;
                return reverseNumber * 10 - reminder;
            }   
            reverseNumber = reverseNumber * 10 + reminder;
        }
        return -1 * reverseNumber;
    }
    
    int reverse(int x) {
        if(x == 0) return 0;
        
        int limit = 214748364;
        
        if(x > 0){
            return calculateForPositiveNumber(x, limit);
        }
        else{
           return calculateForNegativeNumber(x, limit); 
        }
        return 0;
    }
};
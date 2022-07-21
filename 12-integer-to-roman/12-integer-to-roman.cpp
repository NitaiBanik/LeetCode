class Solution {
public:
    string intToRoman(int num) {
       int integetValue[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
       string romanValue[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string answer ="";
    
        for(int i = 0; i < 13; i++){
            if(!num) break;
            
            int how = num / integetValue[i];
            num %= integetValue[i];
        
            while(how--)
            answer += romanValue[i];
        } 
        return answer;
    }
};
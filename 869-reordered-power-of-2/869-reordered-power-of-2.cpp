class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<vector<int>> frequency(32, vector<int>(10, 0));
        
    for(int i = 0;  i< 31; i++){
        int value = 1 << i;
        
        while(value != 0){
            frequency[i][value%10]++;
            value/=10;
        }
    }
       vector<int> fre(10, 0);
        
        while(n!=0){
            fre[n%10]++;
            n/=10;
        }
        
        for(int i = 0; i < 31; i++){
            if(frequency[i] == fre) return true;
        }
        
        return false;
    }
};
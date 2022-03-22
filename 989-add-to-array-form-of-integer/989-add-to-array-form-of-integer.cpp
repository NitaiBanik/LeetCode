class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        
        string num1 = "";
        for(auto chr: num){
            num1 += (char)(chr + '0');
        }
        
        string num2 = "";
        
        while(k != 0)
        {
            num2 +=(char)(k%10 + '0');
            k/=10;
        }
        
        reverse(num2.begin(), num2.end());
        
        int maxln = max(num2.size(), num1.size());
        maxln -= min(num2.size(), num1.size());
        
        string str = "";
        while(maxln--) str+='0';
        
        if(num2.size() > num1.size()) num1 = str + num1;
        else num2 = str + num2;
        
        int rem = 0;
        
        //cout<<num1<<" "<<num2<<endl;
        for(int i = num1.size() -1; i>=0; i--){
            rem = rem + (num1[i] - '0') + (num2[i] - '0');
            
            num2[i] = (char)((rem % 10) + '0');
            rem/=10;
            
           // cout<<rem<<endl;
        }
        
        //reverse(num2.begin(), num2.end());
        
        if(rem != 0)
            num2 = (char)(rem + '0') + num2;
        
        vector<int>vec(num2.size(), 0);
        
        for(int i = 0; i < num2.size(); i++)
            vec[i] = num2[i] - '0';
        
        return vec;
        
    }
};
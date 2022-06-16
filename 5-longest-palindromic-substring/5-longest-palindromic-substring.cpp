class Solution {
public:
    string longestPalindrome(string s) {
        string temp = "";
        for(int i = 0; i < s.size(); i++)
            temp = temp + s[i] + '|';
        
        cout<<"temp = "<<temp<<endl;
        
        int lf = 0, rt = 0, mx = 0;
        
        for(int i = 0; i < temp.size(); i++){
            int cnt = 1;
            for(int j = 0; j < temp.size(); j++){
                if((i - j >= 0) && (i + j < temp.size()) && temp[i - j] == temp[i + j])
                {
                  //  cout<<i-j<<endl;
                    cnt+=2;
                    if(cnt > mx)
                    {
                        mx = max(cnt, mx);
                        lf = i - j, rt = i + j;
                    }
                }
                else break;
            }
        }
        s = "";
        cout<<temp<<endl;
        
        for(int i = lf; i <= rt; i++)
            if(temp[i] != '|')
                s += temp[i];
        
        return s;
    }
};
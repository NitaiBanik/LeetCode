class Solution {
public:
    int firstUniqChar(string s) {
       int mp[130] = {0};
        for(int i = 0 ; i <s.size(); i++)
            mp[s[i]]++;
        for(int i = 0 ; i <s.size(); i++)
            if(mp[s[i]]==1)
                return i;
        return -1;
    }
};
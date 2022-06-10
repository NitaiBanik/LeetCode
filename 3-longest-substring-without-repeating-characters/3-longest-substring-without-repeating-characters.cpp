class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int beg = 0, mx = 0;
        int arr[200] = {0};
        for(int i = 0; i < s.size(); i++){
            arr[s[i]]++;
            while(arr[s[i]] > 1){
                arr[s[beg]]--;
                beg++;}
            mx = max(mx, i - beg + 1);
        }
        return mx;
    }
};
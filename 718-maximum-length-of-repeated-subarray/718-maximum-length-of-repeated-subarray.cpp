class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<int> prev(nums2.size(), 0);
        vector<int> now(nums2.size(), 0);
        
        int mx = 0;
        for(int i = 0; i < nums1.size(); i++){
            for(int j = 0; j < nums2.size(); j++){
                now[j]=0;
                if(i == 0 || j == 0){
                    if(nums1[i] == nums2[j])
                        now[j] = 1;
                }
                else{
                    if(nums1[i] == nums2[j])
                        now[j] = 1 + prev[j-1];
                }
                
                mx = max(mx, now[j]);
            }
            prev = now;
        }
        return mx;
    }
};
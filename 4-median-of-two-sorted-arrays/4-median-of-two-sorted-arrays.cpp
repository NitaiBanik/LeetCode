class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        
        int ln1 = nums1.size(), ln2 = nums2.size();
        
        int lo = 0, hi = ln1;
        
        while(lo <= hi){
            int pos1 = (lo + hi) >> 1;
            int pos2 = ((ln1 + ln2 + 1) >> 1) - pos1;
            
            int leftValue1 = pos1 == 0 ? INT_MIN: nums1[pos1 - 1];
            int leftValue2 = pos2 == 0 ? INT_MIN: nums2[pos2 - 1];
            
            int rightValue1 = pos1 == ln1 ? INT_MAX: nums1[pos1];
            int rightValue2 = pos2 == ln2 ? INT_MAX: nums2[pos2];
            
            if(leftValue1 <= rightValue2 && leftValue2 <= rightValue1){
                if((ln1 + ln2) % 2 == 0){
                    return (max(leftValue1, leftValue2) + min(rightValue1, rightValue2)) / 2.0;
                }
                else{
                    return max(leftValue1, leftValue2);
                }
            }
            
            else if(leftValue1 > rightValue2){
                hi = pos1 - 1;
            }
            else {
                lo = pos1 + 1;
            }
        }
        
        return 0.0;
    }
};
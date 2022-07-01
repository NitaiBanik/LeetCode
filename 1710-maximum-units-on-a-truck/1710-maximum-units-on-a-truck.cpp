class Solution {
public:
    static bool comp(vector<int>& boxType1, vector<int>& boxType2){
        return boxType1[1] > boxType2[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
     sort(boxTypes.begin(), boxTypes.end(), comp);  
    
     int ans = 0;   
    for(auto box : boxTypes){
        if(truckSize <= 0) break;
        
        int mn = min(truckSize, box[0]);
        truckSize -= mn;
        ans += mn * box[1];
    }
        
        return ans;
    }
};
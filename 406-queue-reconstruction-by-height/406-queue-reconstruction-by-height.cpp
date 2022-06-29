class Solution {
public:
    static bool comp(vector<int>& first, vector<int>& second){
       if(first[0] == second[0]) return first[1] < second[1];
        return first[0] > second[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& peoples) {
        sort(peoples.begin(), peoples.end(), comp);
        
        vector<vector<int>> result;
        
        for(int i = 0; i < peoples.size(); i++){
            result.insert(result.begin() + peoples[i][1], peoples[i]);
        }
        
        return result;
    }
};
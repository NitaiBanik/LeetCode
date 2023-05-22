class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mp;
        vector<int>vec;
        vector<pair<int,int>>frequency;
        
        int mx = 0;
        for(int i = 0; i < nums.size(); i++)
            mp[nums[i]]++;
        
          for(int i = 0; i < nums.size(); i++)
          {
              if(mp[nums[i]]>0){
                  frequency.push_back({mp[nums[i]],nums[i]});
                  mp[nums[i]] = 0;
              }
          }
        
        sort(frequency.begin(), frequency.end(), greater<>());
        
        for(int i = 0; i < k; i++){
            vec.push_back(frequency[i].second);
        }
        
        return vec;
    }
};
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> frequecyOfNumbers;
        
        for(auto value: arr)
            frequecyOfNumbers[value]++;
        
        vector<int> frequencies;
        for(auto value: frequecyOfNumbers)
            frequencies.push_back(value.second);
        
        sort(frequencies.begin(), frequencies.end());
        
        int cnt = 0, id = 0;
        
        for(int i = frequencies.size() - 1; i >= 0; i--){
            id++;
            cnt += frequencies[i];
            if(cnt >= arr.size() / 2)
                return id;
        }
        return -1;    
    }
};
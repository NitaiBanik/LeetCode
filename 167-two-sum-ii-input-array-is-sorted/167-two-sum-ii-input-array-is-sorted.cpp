class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int beg = 0, end = numbers.size() - 1;
        
        while(beg < end){
            if(numbers[beg] + numbers[end] == target)
                return {beg + 1, end + 1};
            else if(numbers[beg] + numbers[end] > target)
                end--;
            else beg++;
            
        }
        
        return {1,1};
        
    }
};
class Solution {
public: 
    string convertToString(long long num1, long long num2){
        if(num1 == num2) return to_string(num1);
        return to_string(num1) + "->" + to_string(num2);
    }
    vector<string> summaryRanges(vector<int>& nums) {
        
        int start = 0;
        vector<string> ranges;
        
        while(start < nums.size()){
            long long left = nums[start];
            long long right = left;
            
            while(start < nums.size() && nums[start] == right)
                  right++, start++;
            
        //cout<<"left = "<<left<<" right "<<right-1<<endl;
           string range =  convertToString(left, right - 1);
           ranges.push_back(range);
        }
        
        return ranges;
    }
};
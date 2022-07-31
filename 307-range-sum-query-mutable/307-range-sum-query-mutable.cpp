class NumArray {
public:
    vector<int> blockSum;
    vector<int> numbers;
    int sq;
    NumArray(vector<int>& nums) {
        numbers = nums;
        
        sq = sqrt(nums.size()) + 1;
        blockSum = vector<int>(nums.size() / sq + 2, 0);
        
        for(int i = 0; i < nums.size(); i++){
            blockSum[i / sq] += nums[i];
        }
        
    }
    
    void update(int index, int val) {
        int blockNumber = index / sq;
        blockSum[blockNumber] -= numbers[index] - val;   
        numbers[index] = val;
    }
    
    int sumRange(int left, int right) {
        
        int startBlock = left / sq;
        int endBlock = right / sq; 
        int sum = 0;
        
        if(startBlock == endBlock){
            for(int i = left; i <= right; i++)
                sum += numbers[i];
            return sum;
        }
        
        for(int i = startBlock + 1; i < endBlock; i++)
            sum += blockSum[i];
        
        //cout<<"sum here1 = "<<sum<<endl;
        
        for(int i = left; i < (startBlock + 1) * sq; i++)
            sum += numbers[i];
        
        ///cout<<"sum here 2 = "<<sum<<endl;
        
        for(int i = endBlock * sq; i <= right; i++)
            sum += numbers[i];
        
        //cout<<"sum here 3 = "<<sum<<endl;
        
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
class RandomizedSet {
public:
    vector<int> values;
    unordered_map<int, int> valueWithIndex;
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(valueWithIndex.find(val) != valueWithIndex.end()){
            return false;
        }
        else{
            values.push_back(val);
            valueWithIndex[val] = values.size() - 1;
            
            return true;
        }
    }
    
    bool remove(int val) {
        if(valueWithIndex.find(val) == valueWithIndex.end()){
            return false;
        }
        else{
        int last_value = values[values.size() - 1];
        values.pop_back();
        
        int deleted_value_index = valueWithIndex[val];
        
        values[deleted_value_index] = last_value;
        valueWithIndex[last_value] = deleted_value_index;
        
        valueWithIndex.erase(val);
            
        return true;
        
        }
    }
    
    int getRandom() {
        return values[rand() % values.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
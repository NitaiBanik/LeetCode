class RandomizedSet {
public:
    set<int> st;
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        auto pos = st.find(val);
        if(pos != st.end()){
            return false; 
        }
        else{
            st.insert(val);
            return true;
        }
    }
    
    bool remove(int val) {
        auto pos = st.find(val);
        if(pos != st.end()){
            st.erase(pos);
            return true; 
        }
        else{
            return false;
        }
    }
    
    int getRandom() {
        auto pos = st.begin();
        int sz= st.size();
        int rnd = rand() % sz;
        while(rnd--) pos++;
        return *pos;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
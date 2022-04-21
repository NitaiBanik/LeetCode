class MyHashSet {
public:
    vector<int>myHashSet;
    MyHashSet() {
        vector<int>myHashSett(33334, 0);
        myHashSet = myHashSett;
    }
    
    void add(int key) {
        int position = key/30;
        int val = myHashSet[position];
        val |= (1<<(key%30));
        
         //cout<<"After add val = "<<val<<endl;
        
       myHashSet[position] = val; 
    }
    
    void remove(int key) {
        int position = key/30;
        int val = myHashSet[position];
        val &= ~(1<<(key%30));
        
         myHashSet[position] = val; 
    }
    
    bool contains(int key) {
        int position = key/30;
        int val = myHashSet[position];
        
       // cout<<"val = "<<val<<endl;
        
        return  (val & (1<<(key%30)))> 0;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
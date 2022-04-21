class MyHashSet {
public:
    vector<int>myHashSet;
    MyHashSet() {
        vector<int>myHashSett(1000005, 0);
        myHashSet = myHashSett;
    }
    
    void add(int key) {
       myHashSet[key] = 1; 
    }
    
    void remove(int key) {
         myHashSet[key] = 0;
    }
    
    bool contains(int key) {
        return  myHashSet[key] == 1;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
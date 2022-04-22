int hashh[1000001];
class MyHashMap {
public:
    MyHashMap() {
        memset(hashh, -1, sizeof(hashh));   
    }
    
    void put(int key, int value) {
        hashh[key] = value;
    }
    
    int get(int key) {
        return hashh[key];  
    }
    
    void remove(int key) {
        hashh[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
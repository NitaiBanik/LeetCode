class LRUCache {
public:
    queue<pair<int, int>> timeAndKey;
    map<int, pair<int, int>> KeysWithValues;
    int time, sz;
    
    LRUCache(int capacity) {
        sz = capacity;
        time = 0;
    }
    
    int get(int key) {
        int value = -1;
        if(KeysWithValues.count(key) > 0){
            time++;
            timeAndKey.push({time, key});
            value = KeysWithValues[key].first;
            KeysWithValues[key].second = time;
        }
        
        return value;
    }
    
    void put(int key, int value) {
        time++;
        timeAndKey.push({time,key});
        if(KeysWithValues.count(key) == 0){
             KeysWithValues[key] = {value, time};
            if(KeysWithValues.size() > sz){
                while(timeAndKey.front().first != KeysWithValues[timeAndKey.front().second].second)
                    timeAndKey.pop();
                int keyToDelete = timeAndKey.front().second;
                timeAndKey.pop();
                KeysWithValues.erase(keyToDelete);
            }
        }
        else{
            KeysWithValues[key] = {value, time};
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
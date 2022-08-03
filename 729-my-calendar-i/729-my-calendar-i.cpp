class MyCalendar {
public:
    map<int, int>slots;
    MyCalendar() {
        slots.clear(); 
    }
    
    bool book(int start, int end) {
        auto it = slots.upper_bound(start);
        if(it != slots.end() && (*it).second < end) return false;
        else slots.insert({end, start});
        
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
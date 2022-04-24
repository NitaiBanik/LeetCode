class UndergroundSystem {
public:
    map<int, string>startStation;
    map<int, int>startTime;
    
    map<pair<string, string>, int>startEndStationCount;
    map<pair<string, string>, int>startEndStationTotal;
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        startStation[id] = stationName;
        startTime[id] = t;
    }
    
    void checkOut(int id, string stationName, int t) {
        string start = startStation[id];
        int startTimee = startTime[id];
        
        startEndStationCount[{start, stationName}]++;
        startEndStationTotal[{start, stationName}] += (t - startTimee);
        
    }
    
    double getAverageTime(string startStation, string endStation) {
        return (double)startEndStationTotal[{startStation, endStation}] / (double)startEndStationCount[{startStation, endStation}];
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
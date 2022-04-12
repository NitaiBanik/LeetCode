class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
        int prevDeviceCount = 0, ans = 0;
        
        for(auto beams: bank){
            cout<<beams<<endl;
            int currentDeviceCount = 0;
            for(auto beam: beams)
                currentDeviceCount += (beam - '0');
                        
            if(currentDeviceCount > 0)
            {
                ans += (prevDeviceCount * currentDeviceCount);
                prevDeviceCount = currentDeviceCount;
            }
        }
        return ans;
    }
};
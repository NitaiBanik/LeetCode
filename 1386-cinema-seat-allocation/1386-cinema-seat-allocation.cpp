class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        int ans = 2 * n;
        if(reservedSeats.size() == 0) return ans;
        sort(reservedSeats.begin(), reservedSeats.end());
        
        vector<int>vec;
        
        reservedSeats.push_back({999999999, -1});
        
        for(int i = 0 ; i < reservedSeats.size() - 1; i++){
        if(reservedSeats[i][0] == reservedSeats[i + 1][0]){
            vec.push_back(reservedSeats[i][1]);
        }   
        else{
            vec.push_back(reservedSeats[i][1]);
            int cnt = 0;
            for(auto num: vec){
                if(num == 6 || num == 7 || num == 8 || num == 9){
                    cnt++;
                    break;
                }
            }
             for(auto num: vec){
                if(num == 3 || num == 2 || num == 4 || num == 5){
                   cnt++;
                    break;
                }
            }
            if(cnt == 2){
                int faka = 0;
            for(auto num: vec){
                if(num == 4 || num == 5 || num == 6 || num == 7){
                    faka = 1;
                    break;
                }
            }
                if(faka == 0) cnt--;
            }
            ans -= cnt;
            vec.clear();
        }
        }
        return ans;
    }
};
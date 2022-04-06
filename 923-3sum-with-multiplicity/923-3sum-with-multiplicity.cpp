class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int mod = 1000000000 + 7;
        
        sort(arr.begin(), arr.end());
        
        long long ans = 0;
        
        for(int i = 0; i < arr.size() - 2; i++){
            int T = target - arr[i];
            
            int  lf = i + 1, rt = arr.size() - 1;
            
            while(lf < rt){
                if(arr[lf] + arr[rt] > T)
                    rt--;
                else if(arr[lf] + arr[rt] < T)
                    lf++;
                else if(arr[lf] != arr[rt]){

                    int x = 1, y = 1;
                    while(lf + 1 < rt && arr[lf] == arr[lf + 1]){
                        lf++;
                        x++;
                    }
                    
                     while(rt - 1 > lf && arr[rt] == arr[rt - 1]){
                        rt--;
                        y++;
                     }
                    
                    ans += (x * y);
                    ans %= mod;
                    
                    lf++;
                    rt--;
                }
                else{
                    long long ln = (rt - lf + 1);
                    ln *= (ln - 1);
                    
                    ans += (ln / 2);
                    ans %= mod;   
                    break;
                }
            }
        }
        return ans;
    }
};
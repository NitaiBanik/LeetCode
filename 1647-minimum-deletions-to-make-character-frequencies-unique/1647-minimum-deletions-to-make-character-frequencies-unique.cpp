class Solution {
public:
    int minDeletions(string s) {
        int arr[26] ={0};
        
        for(auto chr: s)
            arr[chr-'a']++;
        
        sort(arr, arr + 26);    
        map<int, int>freq;
        
        int del = 0;
        
        for(int i = 25; i>=0; i--){
            if(arr[i] == 0) continue;
           for(int j = 0; j <= arr[i]; j++){
               if(freq[arr[i] - j] == 0){
                   cout<<arr[i]- j<<endl;
                   del += j;
                   freq[arr[i] - j] = 1;
                   break;
               }
               if(j == arr[i])
                   del += j;
           } 
        }
        
        return del;
    }
};
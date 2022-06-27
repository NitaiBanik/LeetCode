public class Solution {
    public int MinPartitions(string n) {
        int sum = 0, mx = 0;
        
        for(int i = n.Length - 1; i >= 0; i--){
            int value = n[i]-'0';

            mx = Math.Max(mx, value);
        }
        return  mx;
    }
}
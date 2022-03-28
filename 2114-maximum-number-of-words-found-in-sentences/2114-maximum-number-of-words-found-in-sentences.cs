public class Solution {
    public int MostWordsFound(string[] sentences) {
        int mx = 0;
        
        foreach(var s in sentences){
            var words = s.Split(' ');
            mx = Math.Max(mx, words.Length);
        }
        
        return mx;
    }
}
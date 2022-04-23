class Solution {
public:
     map<int, string>urlMapper;
    int pos = -1;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        
        urlMapper[++pos] = longUrl;
        
        return to_string(pos);
        
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int pos = stoi(shortUrl);
        return urlMapper[pos];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
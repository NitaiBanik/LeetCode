class Solution {
public:
    //string urlMapper[10001];
   // int pos = -1;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
       // cout<<"agge = long"<<longUrl<<endl;
        for(int i = 0; i < longUrl.size(); i++)
            longUrl[i] = (char)longUrl[i] - 20;
      //  cout<<"pore long = "<<longUrl<<endl;
        return longUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
       // cout<<"agge short = "<<shortUrl<<endl;
        
         for(int i = 0; i < shortUrl.size(); i++)
            shortUrl[i] = (char)shortUrl[i] + 20;
        
       //  cout<<"pore short = "<<shortUrl<<endl;
        return shortUrl;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
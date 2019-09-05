// LeetCode 535 Encode and Decode TinyURL.cpp

class Solution {
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (u2i.find(longUrl) != u2i.end()) {
            return pre + to_string(u2i[longUrl]);
        }
        int i = u2i.size();
        u2i[longUrl] = i;
        i2u.push_back(longUrl);
        return pre + to_string(i);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return i2u[stoi(shortUrl.substr(pre.size()))];
    }
    
private:
    string pre = "http://tinyurl.com/";
    unordered_map<string, int> u2i;
    vector<string> i2u;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
// 535. Encode and Decode TinyURL

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    // Encodes a URL to a shortened URL.
    const string baseUrl = "http://tinyurl.com/";
    const string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    map<string,string> codeToUrl, UrlToCode;

    string generateCode() {
        string code;
        for(int i = 0; i < 6; i++) {
            code += chars[rand() % chars.size()];
        }
        return code;
    }

    string encode(string longUrl) {
        if(UrlToCode.find(longUrl) != UrlToCode.end()) {
            return UrlToCode[longUrl];
        }
        string code;
        do {
            code = generateCode();
        } while(UrlToCode.find(code) != UrlToCode.end());
        UrlToCode[longUrl] = code;
        codeToUrl[code] = longUrl;
        return baseUrl + code;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string code = shortUrl.substr(baseUrl.size());
        if(codeToUrl.find(code) != codeToUrl.end()) {
            return codeToUrl[code];
        }
        return "";
    }
};

//
//  minWindow.cpp
//  learn-lcweak
//
//  Created by iMac on 2023/8/24.
//

#include "minWindow.hpp"

string minWindow(string s, string t) {
    
    if (t.size() > s.size()) return "";
    if (s == t) return s;
    
    string res = string(s.size() + 1, ' ');
    
    unordered_map<char, int>need;
    for (char c: t) {
        need[c]++;
    }
    
    int l = 0, r = 0, windowSize = 0;
    unordered_map<char, int>window;
    
    while (r < s.size()) {
        char c = s[r++];
        
        if (need.count(c)) {
            window[c]++;
            if (window[c] == need[c]) {
                windowSize++;
            }
        }
        
        while (windowSize == need.size()) {
            if (r-l < res.size()) {
                res = s.substr(l, r-l);
            }
            char left = s[l++];
            if (window.count(left)) {
                window[left]--;
                if (window[left] < need[left]) {
                    windowSize--;
                }
            }
        }
    }
    
    return res == string(s.size() + 1, ' ') ? "" : res;
}

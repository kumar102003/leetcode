#include<bits/stdc++.h>
class Solution {
public:
   #include <vector>

bool isPalindrome(string s) {
    vector<char> temp;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            temp.push_back(s[i]);
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] + 32;
            temp.push_back(s[i]);
        } else if (s[i] >= '0' && s[i] <= '9') {
            temp.push_back(s[i]);
        }
    }
    int i = 0;
    int e = temp.size() - 1;
    while (i < e) {
        if (temp[i] != temp[e]) {
            return false;
        }
        i++;
        e--;
    }
    return true;
}

};
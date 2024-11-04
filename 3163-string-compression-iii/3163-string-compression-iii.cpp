class Solution {
public:
   string compressedString(string word) {
        string comp;
        int n = word.length();
        int i = 0;

        while (i < n) {
            char ch = word[i];
            int count = 0;
            while (i < n && word[i] == ch && count < 9) {
                count++;
                i++;
            }
            comp += to_string(count) + ch;
        }

        return comp;
    }
};
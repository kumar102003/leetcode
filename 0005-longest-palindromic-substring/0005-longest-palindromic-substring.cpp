class Solution {
public:
    
    vector<vector<int>> dp;

   
    bool isPalindrome(string &s, int i, int j) {
        if (i >= j) return true;
        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == s[j] && isPalindrome(s, i + 1, j - 1)) {
            return dp[i][j] = 1;
        }
        return dp[i][j] = 0;
    }

    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 0) return "";

       
        dp.assign(n, vector<int>(n, -1));

        int maxLen = 1;
        int start = 0;

        
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isPalindrome(s, i, j)) {
                    if (j - i + 1 > maxLen) {
                        maxLen = j - i + 1;
                        start = i;
                    }
                }
            }
        }


        return s.substr(start, maxLen);
    }
};

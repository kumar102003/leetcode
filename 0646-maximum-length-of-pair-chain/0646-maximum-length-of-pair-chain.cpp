class Solution {
public:
    int n;
    int t[1001][1001];  // DP table to store results

    int solve(vector<vector<int>>& pairs, int i, int p) {
        if (i >= n) {
            return 0;  // Base case: no more pairs left
        }

        if (p != -1 && t[p][i] != -1) {  
            return t[p][i];  // Return the precomputed value
        }

        int take = 0;
        // Take the current pair if it's valid (p == -1 means no previous pair)
        if (p == -1 || pairs[i][0] > pairs[p][1]) {
            take = 1 + solve(pairs, i + 1, i);  // Include current pair
        }

        // Skip the current pair
        int skip = solve(pairs, i + 1, p);

        // Store the result if a previous pair exists
        if (p != -1) {
            t[p][i] = max(take, skip);
        }

        return max(take, skip);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        n = pairs.size();
        memset(t, -1, sizeof(t));  // Initialize the DP table with -1

        // Sort pairs based on the first element (default sorting)
        sort(begin(pairs), end(pairs));

        // Start solving from index 0 with no previous pair selected (-1)
        return solve(pairs, 0, -1);
    }
};

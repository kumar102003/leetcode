class Solution {
public:
    int solve(int idx, int currOr, int maxOr, vector<int>& nums, unordered_map<string, int>& memo) {
        if (idx == nums.size()) {
            return currOr == maxOr ? 1 : 0;
        }

        string key = to_string(idx) + "|" + to_string(currOr);
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }

        // Take the current number
        int take = solve(idx + 1, currOr | nums[idx], maxOr, nums, memo);

        // Skip the current number
        int skip = solve(idx + 1, currOr, maxOr, nums, memo);

        return memo[key] = take + skip;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxOr = 0;
        for (auto &num : nums) {
            maxOr |= num;
        }

        unordered_map<string, int> memo;
        return solve(0, 0, maxOr, nums, memo);
    }
};

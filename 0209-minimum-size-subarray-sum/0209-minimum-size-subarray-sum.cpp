class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int s = 0;
        int e = 0;
        int sum = 0;
        int minLength = INT_MAX;

        while (e < nums.size()) {
            sum += nums[e++];
            
            while (sum >= target) {
                minLength = min(minLength, e - s);
                sum -= nums[s++];
            }
        }
        
        return minLength == INT_MAX ? 0 : minLength;
    }
};

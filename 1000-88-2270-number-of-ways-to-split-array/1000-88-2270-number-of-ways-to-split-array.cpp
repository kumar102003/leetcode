class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum = 0;
        int n = nums.size();
        for( int i = 0 ; i < nums.size(); i++){
            sum+=nums[i];
        }
      long long  currSum = 0;
      long long  count  = 0;
        for( int i = 0 ; i < n-1; i++){
           currSum +=nums[i];
           long long  rem = sum - currSum ;
           if(currSum >= rem){
            count++;
           }
        }
        return count ;
    }
};
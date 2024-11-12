class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long>temp(n);
        int maxi = 0;
        for( int i = 0 ; i < n ; i++){
            maxi = max(maxi,nums[i]);
           temp[i]= nums[i]+maxi;
        }
        for( int i = 1 ; i < temp.size(); i++){
           temp[i]= temp[i]+temp[i-1];
        }
        return temp;
    }
};
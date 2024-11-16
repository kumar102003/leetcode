class Solution {
public:
   bool isSorted(int s , int e , vector<int>nums){
       for( int i = s ; i <e ; i++){
          if(nums[i]>=nums[i+1]){
            return false;
          }
           else if(nums[i+1]!=nums[i]+1){
return false;
           }
       }
       return true;
   }
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans(n-k+1);
        int i = 0 ; 
        int j = k-1;
        while(j<n){
            if(isSorted(i,j,nums)){
                ans[i]=*max_element(begin(nums) + i, begin(nums) + j+1);
                
            }
            else{
                ans[i]= -1;
            }
            i++;
            j++;
        }
        return ans;
    }
};
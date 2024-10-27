class Solution {
public:
    int findMin(vector<int>& nums) {
        // int size = nums.size();
        // int s = 0;
        // int e = size-1;
        // int ans = -1;
        // while(s<e){
        //     int mid = s + (e-s)/2;

        //     if(nums[mid]>nums[e]){
        //         s = mid+1;
        //     }
        //     // else if(nums[mid]<nums[e]{
        //     //     e = mid-1;
        //     // }
        //     else{
        //         e = mid;
        //        // ans = mid;
        //     }
        // }
        // return nums[e];
        int mini = INT_MAX;
        for( int i =0 ; i<nums.size(); i++){
            mini = min(mini,nums[i]);
        }
        return mini;
    }
};
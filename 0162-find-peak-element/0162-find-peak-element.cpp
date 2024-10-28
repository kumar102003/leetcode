class Solution {
public:
    int findPeakElement(vector<int>& nums) {


        //Approach 1 


        // int n = nums.size();
        // if(nums.size()==1){
        //     return 0;
        // }
        // if(nums[0]>nums[1]){
        //     return 0;
        // }
        // if(nums[n-1]>nums[n-2]){
        //     return n-1;
        // }
        // int s = 1;
        // int e =  n-2;
        // while(s<=e){
        //     int mid = s + (e-s)/2;

        //     if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
        //         return mid;
        //     }
        //     else if(nums[mid-1]< nums[mid]){
        //         s = mid+1;
        //     }
        //     else{
        //         e = mid-1;
        //     }
        // }
        // return -1;


        //Approach 2 
        int s = 0;
        int e = nums.size() - 1;
        
        while (s < e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] > nums[mid + 1]) {
                e = mid;
            } else {
                s = mid + 1;
            }
        }
        return s;
    }
};
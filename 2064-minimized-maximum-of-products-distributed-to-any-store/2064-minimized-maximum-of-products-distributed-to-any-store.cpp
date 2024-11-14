class Solution {
public:
 bool isPossible(int x , vector<int>quantities , int n ){
    for(int pd:quantities){
        n-=(pd+x-1)/x;
        if(n<0){
            return false;
        }
    }
    return true;
 }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l= 1;
        int r = *max_element(begin(quantities), end(quantities));
        int ans = 0;
        while(l<=r){
            int mid = l + ( r-l)/2;
            if(isPossible(mid,quantities,n)){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};
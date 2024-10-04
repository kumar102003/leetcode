class Solution {
public:
    int N  , M , K ;
    int t[51][51][101];
    
    int MOD = 1e9+7;
    int solve ( int i , int cost , int maxV){
        if(i==N){
            if(cost==K){
                return 1;
                }
            return 0;
            }
        // 
        if(t[i][cost][maxV]!=-1){
return  t[i][cost][maxV];
        }
        int result = 0;
        for( int num = 1 ; num <=M ; num++){
            if(num>maxV){
                result = (result + solve(i+1 , cost+1 , num))%MOD;
                
             }
            else{
                result = (result + solve (i +1 , cost , maxV))%MOD;
            }
        }
        return t[i][cost][maxV] = result%MOD;
    }
    int numOfArrays(int n, int m, int k) {
        N = n ;
        M = m;
        K = k;
        memset(t , -1 , sizeof(t));
        return solve(0,0,0);
    }
};
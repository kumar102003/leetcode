class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int m   = s1.size();
        int n = s2.size();
        vector<vector<int>>temp(m+1,vector<int>(n+1));
        for( int i = 0 ; i <=m ; i++){
              temp[i][0]= 0;
        }
        for( int j = 0 ; j <=n; j++){
              temp[0][j]= 0;
        }
        for( int i = 1 ; i <= m ; i++){
            for( int j = 1 ; j <= n ; j++){
                if(s1[i-1]==s2[j-1]){
                    temp[i][j]=1+temp[i-1][j-1];
                }
                else{
                    temp[i][j]= max(temp[i-1][j],temp[i][j-1]);

                }
            }
        }

        // if we need to return only length of LCS we can return last column and row 
        int i = m;
        int j = n;
        string LCS = "";

        while(i>0 && j > 0){
            if(s1[i-1]==s2[j-1]){
                LCS = LCS + s1[i-1];
                i--;
                j--;
            }
            else{
                if(temp[i-1][j]>temp[i][j-1]){
                    i--;
                }else
                {
                   j--;
                }
            }
        }
        // reverse(begin(LCS),end(LCS));
        // cout<<LCS<<" "<<endl;
        return temp[m][n];
       
    }
};
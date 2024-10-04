class Solution {
public:
    int n ;
    int t[1001][1001];
    
    static bool comp( string & a, string& b ){
     return a.length()<b.length();
    }
    bool prec(const string &prev, const string &curr) {
    int N = prev.length();
    int M = curr.length();
    if (N >= M || M - N != 1) {
        return false;
    }
    int i = 0, j = 0;
    while (i < N && j < M) {
        if (prev[i] == curr[j]) {
            i++;
        }
        j++;
    }
    return i == N; 
}
    int lis( vector<string>& words, int i , int p ){
        if(i>=n){
          return 0;
        }
        //take 
        if(p!=-1 &&  t[i][p]!=-1){
            return t[i][p];
            
}
        int take = 0;
        if(p == -1 || (p >= 0 && prec(words[p], words[i]))){
            take = 1+ lis(words,i+1,i);
        }
        //skip
        int skip = lis(words,i+1,p);
        
        if(p!=-1){
            t[i][p]= max(take,skip);
         
        }
        return max(take,skip);
        
        
        
        
        
}
    int longestStrChain(vector<string>& words) {
        n = words.size();
        memset(t,-1,sizeof(t));
        
        sort( begin(words), end(words), comp);
        return lis (words, 0 , -1);
    }
};
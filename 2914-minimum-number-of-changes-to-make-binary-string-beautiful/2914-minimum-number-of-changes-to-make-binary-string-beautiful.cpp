class Solution {
public:
    int minChanges(string s) {
        int n = s.length();
        int i = 0;
        int count = 0;
        int ans = 0;
        char ch =s[0];
        while( i < n ){
            
          if ( s[i]==ch){
            
            i++;
            count++;
            continue;
          }
        if (s[i]!=ch && count%2==0){

            count= 1;;
            
          }
          else if(s[i]!=ch && count%2!=0){
            ans++;
            count=0;
          }
          ch = s[i];
          i++;
        }
        return ans;
    }
};
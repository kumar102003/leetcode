class Solution {
public:
    bool isCircularSentence(string s) {
        int n = s.length();
        
        if(s[0]!=s[n-1]){
         return false;
        }
        int i = 0;
        while(i<n-1){
            
            if(s[i+1]==' '){
             char ch = s[i];
              i++;
                while(i<n-1 && s[i]==' '){
                 i++;
                }
                if(ch!=s[i]){
                 return false;
                }
                
                
            }
            else{
                i++;
            }
        }
        return true;
    }
};
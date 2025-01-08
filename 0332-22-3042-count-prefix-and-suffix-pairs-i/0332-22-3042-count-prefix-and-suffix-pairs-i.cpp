class Solution {
public:
//  static bool comp(string& a, string& b) {
//     return a.length() < b.length(); // Sort by length (ascending)
// }
  bool isPre(string s1 , string s2){
     int n = s1.length();
     int m = s2.length();
     int i = 0; 
     int j = 0;
     if (n > m) return false;
     while( i < n && j < m){
        if(s1[i]!=s2[j]){
            return false;
        }
 i++;
 j++;
     }
     return true;
  }
  bool isSuf( string s1 , string s2){
     int n = s1.length();
     int m = s2.length();
     int i = n-1 ; 
     int j = m-1;
     if (n > m) return false;
     while( i>= 0 && j >= 0 ){
        if( s1[i]!=s2[j]){
            return false;
        }
        i--;
        j--;
     }
     return true;

  }
    int countPrefixSuffixPairs(vector<string>& words) {
         int n = words.size();
 
        
        int count = 0;
        for ( int i = 0; i < n-1 ; i++){
            for( int j = i+1 ; j < n ; j++){
                if(isPre(words[i], words[j]) && isSuf(words[i], words[j])){
                    count ++;
                }
            }
        }
  return count ;
    }
};
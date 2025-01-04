class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n =  s.length();
      vector<pair<int,int>>index(26, {-1,-1});
      for(int i = 0 ; i < n ; i++){
        char ch = s[i];
        int idx = ch-'a';
        if(index[idx].first==-1){
           index[idx].first = i;
        }
        index[idx].second = i;
      }
       //unordered_set<char>letters;
       int count = 0;
       for( int i = 0 ; i < 26 ; i ++){
        int first_index = index[i].first;
        int sec_index = index[i].second;
        if(first_index==-1){
            continue;
        }
        unordered_set<char>st;
        for( int j = first_index+1 ; j <=sec_index-1 ; j++){
            char ch = s[j];
            st.insert(ch);
        }
        count = count+st.size();
       }
       return count ;
    }
};
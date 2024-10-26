class Solution {
public:
    string generate(string &s){
        int temp[26]={0};
        for( int i = 0 ; i < s.length(); i++){
              temp[s[i]-'a']++;
        }
        string word = "";
        for( int i = 0 ; i< 26; i++){
            if(temp[i]>0){
                word+= string(temp[i], i+'a');
            }
        }
        return  word;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<string>>mp;
        vector<vector<string>>ans;

        for( int i = 0 ; i <  strs.size(); i++){
            string word =strs[i];
            string new_word = generate(word);
            mp[new_word].push_back(word);

        }

        for( auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};